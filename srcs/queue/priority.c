/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:20:35 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/08 13:41:57 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	priority(t_coder *first, t_coder *second, t_parsing	*parsing)
{
	long long int	first_deadline;
	long long int	second_deadline;
	bool			state;

	state = true;
	if (parsing->scheduler) // edf
	{
		first_deadline = parsing->time_to_burnout + first->last_compile;
		second_deadline = parsing->time_to_burnout + second->last_compile;
		if (first_deadline < second_deadline)
			state = false;
	}
	return (state);
}
