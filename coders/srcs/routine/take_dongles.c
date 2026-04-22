/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_dongles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:53:14 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/07 19:53:14 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	take_dongles(t_coder *coder, t_dongle_order *dongle_order)
{
	bool	state;
	struct timespec ts;
	struct timeval  tv;
	

	state = true;
	gettimeofday(&tv, NULL);
	ts.tv_sec = tv.tv_sec + coder->shared->parse_result.dongle_cooldown / 1000;
	ts.tv_nsec = tv.tv_usec * 1000 + ((coder->shared->parse_result.dongle_cooldown) % 1000) * 1000000;
	if (ts.tv_nsec >= 1000000000)
	{
		ts.tv_sec += ts.tv_nsec / 1000000000;
		ts.tv_nsec %= 1000000000;
	}
	pthread_mutex_lock(&dongle_order->first->mutex_dongle);
	while ((coder != dongle_order->first->waiting_queue->coder) && get_is_run(coder))
		pthread_cond_wait(&dongle_order->first->cond_wait_dongle, &dongle_order->first->mutex_dongle);
	while (!check_cooldown(coder, dongle_order->first)  && get_is_run(coder))
		pthread_cond_timedwait(&dongle_order->first->cond_wait_dongle, &dongle_order->first->mutex_dongle, &ts);
	if (!state || !print_state(coder->id, "has taken a dongle", coder))
	{
		pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
		return (false);
	}
	pthread_mutex_lock(&dongle_order->second->mutex_dongle);
	while ((coder != dongle_order->second->waiting_queue->coder) && get_is_run(coder))
		pthread_cond_wait(&dongle_order->second->cond_wait_dongle, &dongle_order->second->mutex_dongle);
	while (!check_cooldown(coder, dongle_order->second) && get_is_run(coder))
		pthread_cond_timedwait(&dongle_order->second->cond_wait_dongle, &dongle_order->second->mutex_dongle, &ts);
	if (!state || !print_state(coder->id, "has taken a dongle", coder))
	{
		pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
		pthread_mutex_unlock(&dongle_order->second->mutex_dongle);
		return (false);
	}
	return (true);
}
