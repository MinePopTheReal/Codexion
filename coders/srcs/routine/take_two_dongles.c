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

bool	take_two_dongles(t_coder *coder, t_dongle_order *dongle_order)
{
	bool			state;
	struct timespec	ts;

	state = true;
	ts = calcul_timespec(coder->shared);
	if (!take_one_dongle(coder, dongle_order->first, &ts))
	{
		pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
		return (false);
	}
	if (!take_one_dongle(coder, dongle_order->second, &ts))
	{
		pthread_mutex_unlock(&dongle_order->first->mutex_dongle);
		pthread_mutex_unlock(&dongle_order->second->mutex_dongle);
		return (false);
	}
	return (true);
}
