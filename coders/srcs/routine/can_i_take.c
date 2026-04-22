/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_i_take.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:03:37 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/23 02:05:22 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>


// bool	can_i_take(t_coder *coder, t_dongle_order *dongle_order)
// {
// 	bool	i_can;

// 	i_can = true;
// 	pthread_mutex_lock(&dongle_order->first->mutex_dongle);
// 	pthread_mutex_lock(&dongle_order->second->mutex_dongle);
// 	if (coder != dongle_order->first->waiting_queue->coder || \
// coder != dongle_order->second->waiting_queue->coder || \
// !check_cooldown(coder, dongle_order))
// 		i_can = false;
// 	pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
// 	pthread_mutex_unlock(&dongle_order->second->mutex_dongle);
// 	return (i_can);
// }
