/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:03:57 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/08 17:03:57 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	check_cooldown(t_coder *coder, t_dongle *first, t_dongle *second)
{
	if (!(first->release_time == -1) && \
get_curr_time_from_start() - first->release_time < \
coder->shared->parse_result.dongle_cooldown)
		return (false);
	else if (!(second->release_time == -1) && \
get_curr_time_from_start() - second->release_time < \
coder->shared->parse_result.dongle_cooldown)
		return (false);
	return (true);
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
	first->release_time = get_curr_time_from_start();
	pthread_mutex_unlock(&first->mutex_dongle);
	second->release_time = get_curr_time_from_start();
	pthread_mutex_unlock(&second->mutex_dongle);

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

bool 	is_done(t_coder *coder)
{
	bool	state;

	state = true;
	pthread_mutex_lock(&coder->mutex_coder);
	if (coder->nb_compiles >= coder->shared->parse_result.number_of_compiles)
		state = false;
	pthread_mutex_unlock(&coder->mutex_coder);
	return (state);
}

bool	wait_dongle(t_coder *coder, t_dongle *first, t_dongle *second)
{
	while (!can_i_take(coder, first, second))
	{
		if (!smart_sleep(1, coder))
			return (false);
	}
	return (true);
}
