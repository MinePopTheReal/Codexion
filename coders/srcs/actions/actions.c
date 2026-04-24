/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:55 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 03:56:24 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	actions(t_coder *coder, t_dongle_order *dongle_order)
{
	if (take_two_dongles(coder, dongle_order))
	{
		if (!compile(coder, dongle_order))
		{
			release_dongles(dongle_order);
			return (false);
		}
		release_dongles(dongle_order);
	}
	else
		return (false);
	if (!debug(coder))
		return (false);
	if (!refactor(coder))
		return (false);
	return (true);
}
