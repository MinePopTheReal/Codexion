/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_dongle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:31:45 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/23 02:06:13 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

void	release_dongles(t_dongle_order *dongle_order)
{
	dongle_order->first->release_time = get_curr_time_from_start();
	pthread_cond_broadcast(&dongle_order->first->cond_wait_dongle);
	pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
	dongle_order->second->release_time = get_curr_time_from_start();
	pthread_cond_broadcast(&dongle_order->second->cond_wait_dongle);
	pthread_mutex_unlock(&dongle_order->second->mutex_dongle);

}
