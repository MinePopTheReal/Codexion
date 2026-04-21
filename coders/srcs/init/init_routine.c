/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:51:29 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 13:47:05 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	init_routine(t_coder *coder, t_dongle_order *dongle_order)
{
	while (!get_sim_is_ready(coder->shared))
		usleep(50);
	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = get_curr_time_from_start();
	pthread_mutex_unlock(&coder->mutex_coder);
	get_first_second(coder, dongle_order);
	if (dongle_order->second == dongle_order->first)
		return (false);
	return (true);
}
