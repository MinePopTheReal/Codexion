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

bool	refactor(t_coder *coder)
{
	long long int	refactor_time;
	bool			state;

	state = true;
	if (!print_state(coder->id, "is refactoring", coder))
		state = false;
	refactor_time = coder->shared->parse_result.time_to_refactor;
	if (!smart_sleep(refactor_time, coder))
		state = false;
	return (state);
}