/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_couldown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:30:25 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/23 02:05:39 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	check_cooldown(t_coder *coder, t_dongle *dongle)
{
	if (!(dongle->release_time == -1) && \
get_curr_time_from_start() - dongle->release_time <= \
coder->shared->parse_result.dongle_cooldown)
		return (false);
	return (true);
}
