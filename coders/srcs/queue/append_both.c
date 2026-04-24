/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:30:57 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	append_both(t_coder *coder, t_dongle_order *dongle_order)
{
	bool	state;

	state = true;
	pthread_mutex_lock(&dongle_order->first->mutex_dongle);
	pthread_mutex_lock(&dongle_order->second->mutex_dongle);
	if (!append_queue(&dongle_order->first->waiting_queue, coder))
	{
		free_queues(coder->shared);
		state = false;
	}
	else if (!append_queue(&dongle_order->second->waiting_queue, coder))
	{
		free_queues(coder->shared);
		state = false;
	}
	pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
	pthread_mutex_unlock(&dongle_order->second->mutex_dongle);
	return (state);
}
