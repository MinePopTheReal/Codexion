/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:46:22 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/30 19:40:41 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	drop_dongle(t_dongle *first, t_dongle *second)
{
	if (!first->is_taken)
	{
		pthread_mutex_unlock(&first->mutex_dongle);
		return (false);
	}
	else if (!second->is_taken)
	{
		pthread_mutex_unlock(&first->mutex_dongle);
		pthread_mutex_unlock(&second->mutex_dongle);
		return (false);
	}
	return (true);
}

bool	taken_dongle(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;

	if (coder->left_dongle < coder->right_dongle)
	{
		first = coder->left_dongle;
		second = coder->right_dongle;
	}
	else
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	pthread_mutex_lock(&first->mutex_dongle);
	first->is_taken = true;
	if (!drop_dongle(first, second))
		return (false);
	print_state(coder->id, "has taken a dongle", coder);
	pthread_mutex_lock(&second->mutex_dongle);
	second->is_taken = true;
	if (!drop_dongle(first, second))
		return (false);
	print_state(coder->id, "has taken a dongle", coder);
	// pthread_mutex_unlock(&first->mutex_dongle);
	// pthread_mutex_unlock(&second->mutex_dongle);

	return (true);
}

bool	compile(t_coder *coder)
{
	long long int	compile_time;

	if (!print_state(coder->id, "is compiling", coder))
		return (NULL);
	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = get_curr_time_from_start();
	pthread_mutex_unlock(&coder->mutex_coder);
	coder->nb_compiles += 1;
	compile_time = coder->shared->parse_result.time_to_compile;
	if (!smart_sleep(compile_time, coder))
		return (false);
	return (true);
}

bool	debug(t_coder *coder)
{
	long long int	debug_time;

	if (!print_state(coder->id, "is debugging", coder))
		return (NULL);
	debug_time = coder->shared->parse_result.time_to_debug;
	if (!smart_sleep(debug_time, coder))
		return (false);
	return (true);
}

bool	refactor(t_coder *coder)
{
	long long int	refactor_time;

	if (!print_state(coder->id, "is refactoring", coder))
		return (NULL);
	refactor_time = coder->shared->parse_result.time_to_refactor;
	if (!smart_sleep(refactor_time, coder))
		return (false);
	return (true);
}

void	*routine(void *ptr)
{
	t_coder	*coder;

	coder = (t_coder *) ptr;
	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = get_curr_time_from_start();
	pthread_mutex_unlock(&coder->mutex_coder);
	while (coder->nb_compiles < coder->shared->parse_result.number_of_compiles)
	{
		if (coder->id % 2 == 0)
			usleep(50);
		if (!taken_dongle(coder))
			return (NULL);
		compile(coder);
		coder->left_dongle->is_taken = false;
		coder->right_dongle->is_taken = false;
		// debug(coder);
		// refactor(coder);
		pthread_mutex_unlock(&coder->right_dongle->mutex_dongle);
		pthread_mutex_unlock(&coder->left_dongle->mutex_dongle);
	}
	return (NULL);
}
