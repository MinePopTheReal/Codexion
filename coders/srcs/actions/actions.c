/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:55 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 11:35:40 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	actions(t_coder *coder, t_dongle_order *dongle_order)
{
	if (take_dongles(coder, dongle_order))
	{
		if (!compile(coder))
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
