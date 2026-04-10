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
	if (!can_i_take(coder, dongle_order))
		return (false);
	pthread_mutex_lock(&dongle_order->first->mutex_dongle);
	if (!print_state(coder->id, "has taken a dongle", coder))
	{
		pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
		return (false);
	}
	pthread_mutex_lock(&dongle_order->second->mutex_dongle);
	if (!print_state(coder->id, "has taken a dongle", coder))
	{
		pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
		pthread_mutex_unlock(&dongle_order->second->mutex_dongle);
		return (false);
	}
	first_pop_queue(&dongle_order->first->waiting_queue);
	first_pop_queue(&dongle_order->second->waiting_queue);
	return (true);
}
