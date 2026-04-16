/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_dongle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:33:00 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/09 23:33:00 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	wait_dongle(t_coder *coder, t_dongle_order *dongle_order)
{
	while (!can_i_take(coder, dongle_order))
	{
		if (!get_is_run(coder))
			return (false);
		usleep(50);
	}
	return (true);
}
