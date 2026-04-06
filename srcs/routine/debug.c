/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:20:02 by marvin            #+#    #+#             */
/*   Updated: 2026/04/06 14:20:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	debug(t_coder *coder)
{
	long long int	debug_time;
	bool			state;

	state = true;
	if (!print_state(coder->id, "is debugging", coder))
		state = false;
	debug_time = coder->shared->parse_result.time_to_debug;
	if (!smart_sleep(debug_time, coder))
		state = false;
	return (state);
}
