/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_couldown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:30:25 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 11:27:27 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	check_cooldown(t_coder *coder, t_dongle_order *dongle_order)
{
	if (!(dongle_order->first->release_time == -1) && \
get_curr_time_from_start() - dongle_order->first->release_time < \
coder->shared->parse_result.dongle_cooldown)
		return (false);
	else if (!(dongle_order->second->release_time == -1) && \
get_curr_time_from_start() - dongle_order->second->release_time < \
coder->shared->parse_result.dongle_cooldown)
		return (false);
	return (true);
}
