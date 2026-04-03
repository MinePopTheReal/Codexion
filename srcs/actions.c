/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:46:22 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/03 19:08:51 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	can_i_take(t_coder *coder, t_dongle *first, t_dongle *second)
{
	bool	i_can;

	i_can = true;
	pthread_mutex_lock(&first->mutex_dongle);
	pthread_mutex_lock(&second->mutex_dongle);
	if (coder != first->waiting_queue->coder || \
coder != second->waiting_queue->coder)
		i_can = false;
	pthread_mutex_unlock(&first->mutex_dongle);
	pthread_mutex_unlock(&second->mutex_dongle);
	return (i_can);
}

void	append_both(t_coder *coder, t_dongle *first, t_dongle *second)
{
	pthread_mutex_lock(&first->mutex_dongle);
	pthread_mutex_lock(&second->mutex_dongle);
	append_queue(&first->waiting_queue, coder);
	append_queue(&second->waiting_queue, coder);
	pthread_mutex_unlock(&first->mutex_dongle);
	pthread_mutex_unlock(&second->mutex_dongle);
}

void	release_dongles(t_dongle *first, t_dongle *second)
{
	pthread_mutex_unlock(&first->mutex_dongle);
	pthread_mutex_unlock(&second->mutex_dongle);
}

bool	taken_dongle(t_coder *coder, t_dongle *first, t_dongle *second)
{
	if (!can_i_take(coder, first, second))
		return (false);
	pthread_mutex_lock(&first->mutex_dongle);
	if (!print_state(coder->id, "has taken a dongle", coder))
	{
		pthread_mutex_unlock(&first->mutex_dongle);
		return (false);
	}
	pthread_mutex_lock(&second->mutex_dongle);
	if (!print_state(coder->id, "has taken a dongle", coder))
	{
		release_dongles(first, second);
		return (false);
	}
	first_pop_queue(&first->waiting_queue);
	first_pop_queue(&second->waiting_queue);
	pthread_mutex_lock(&coder->mutex_coder);
	if ((coder->nb_compiles < coder->shared->parse_result.number_of_compiles - 1))
	{
		// pthread_mutex_lock(&coder->shared->mutex_print);
		// printf("ciao kumbucha coder:%d compiles: %d/%d\n", coder->id, coder->nb_compiles, coder->shared->parse_result.number_of_compiles);
		// pthread_mutex_unlock(&coder->shared->mutex_print);
		append_queue(&first->waiting_queue, coder);
		append_queue(&second->waiting_queue, coder);
	}
	// else
	// 	{
	// 		pthread_mutex_lock(&coder->shared->mutex_print);
	// 		printf("bomboclat coder:%d compiles: %d/%d\n", coder->id, coder->nb_compiles, coder->shared->parse_result.number_of_compiles);
	// 		pthread_mutex_unlock(&coder->shared->mutex_print);
	// 	}
	pthread_mutex_unlock(&coder->mutex_coder);
	return (true);
}

bool	compile(t_coder *coder)
{
	long long int	compile_time;
	bool			state;

	state = true;
	if (!print_state(coder->id, "is compiling", coder))
		return (false);
	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = get_curr_time_from_start();
	// pthread_mutex_lock(&coder->shared->mutex_print);
	// printf("Coder %d compiling (%d)\n", coder->id, coder->nb_compiles);
	// pthread_mutex_unlock(&coder->shared->mutex_print);
	coder->nb_compiles += 1;
	compile_time = coder->shared->parse_result.time_to_compile;
	if (!smart_sleep(compile_time, coder))
		state = false;
	pthread_mutex_unlock(&coder->mutex_coder);
	return (state);
}

bool	debug(t_coder *coder)
{
	long long int	debug_time;

	if (!print_state(coder->id, "is debugging", coder))
		return (false);
	debug_time = coder->shared->parse_result.time_to_debug;
	if (!smart_sleep(debug_time, coder))
		return (false);
	return (true);
}

bool	refactor(t_coder *coder)
{
	long long int	refactor_time;

	if (!print_state(coder->id, "is refactoring", coder))
		return (false);
	refactor_time = coder->shared->parse_result.time_to_refactor;
	if (!smart_sleep(refactor_time, coder))
		return (false);
	return (true);
}

void	get_first_second(t_coder *coder, t_dongle **first, t_dongle **second)
{
	if (coder->left_dongle < coder->right_dongle)
	{
		*first = coder->left_dongle;
		*second = coder->right_dongle;
	}
	else
	{
		*first = coder->right_dongle;
		*second = coder->left_dongle;
	}
}

void	*routine(void *ptr)
{
	t_coder		*coder;
	t_dongle	*first;
	t_dongle	*second;
	int			count;

	first = NULL;
	second = NULL;
	coder = (t_coder *) ptr;
	count = 0;
	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = get_curr_time_from_start();
	pthread_mutex_unlock(&coder->mutex_coder);
	get_first_second(coder, &first, &second);
	if (coder->id % 2 == 0)
		usleep(5);
	append_both(coder, first, second);
	while (true)
	{
		pthread_mutex_lock(&coder->mutex_coder);
		if (coder->nb_compiles >= coder->shared->parse_result.number_of_compiles)
		{
			pthread_mutex_unlock(&coder->mutex_coder);
			break ;
		}
		pthread_mutex_unlock(&coder->mutex_coder);
		
		while (!can_i_take(coder, first, second))
		{
			if (!smart_sleep(1, coder))
				return (NULL);
		}
		if (taken_dongle(coder, first, second))
			compile(coder);
		else
			return (NULL);
		release_dongles(first, second);
	}
	// pthread_mutex_lock(&coder->shared->mutex_print);
	// printf("finish\n");
	// pthread_mutex_unlock(&coder->shared->mutex_print);
	return (NULL);
}
