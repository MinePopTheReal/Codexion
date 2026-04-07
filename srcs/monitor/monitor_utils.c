/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:54:43 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/07 16:43:24 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	sim_is_finish(t_global_data *shared)
{
	bool	state;
	int		i;

	i = 0;
	state = true;
	while (i < shared->parse_result.number_of_coder)
	{
		if (shared->coders[i].nb_compiles < \
shared->parse_result.number_of_compiles)
			state = false;
		i++;
	}
	return (state);
}
