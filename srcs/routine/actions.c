/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:55 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/08 18:16:48 by tmalpert         ###   ########.fr       */
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
		release_dongles(first, second);
	}
	else
		state = false;
	if (!debug(coder))
		state = false;
	if (!refactor(coder))
		state = false;
	return (state);
}
