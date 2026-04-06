/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:46:22 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/06 14:22:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	actions(t_coder *coder, t_dongle *first, t_dongle *second)
{
	bool	state;

	state = true;
	if (taken_dongles(coder, first, second))
	{
		if (!compile(coder))
			state = false;
	}
	else
		state = false;
	release_dongles(first, second);
	if (!debug(coder))
		state = false;
	if (!refactor(coder))
		state = false;
	return (state);
}
