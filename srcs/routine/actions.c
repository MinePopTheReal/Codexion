/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:55 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/09 22:12:40 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	actions(t_coder *coder, t_dongle *first, t_dongle *second)
{
	if (taken_dongles(coder, first, second))
	{
		if (!compile(coder))
		{
			release_dongles(first, second);
			return (false);
		}
		release_dongles(first, second);
	}
	else
		return (false);
	if (!debug(coder))
		return (false);
	if (!refactor(coder))
		return (false);
	return (true);
}
