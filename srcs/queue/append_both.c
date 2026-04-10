/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:30:57 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 16:36:40 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

void	append_both(t_coder *coder, t_dongle_order *dongle_order)
{
	pthread_mutex_lock(&dongle_order->first->mutex_dongle);
	pthread_mutex_lock(&dongle_order->second->mutex_dongle);
	append_queue(&dongle_order->first->waiting_queue, coder);
	append_queue(&dongle_order->second->waiting_queue, coder);
	pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
	pthread_mutex_unlock(&dongle_order->second->mutex_dongle);
}
