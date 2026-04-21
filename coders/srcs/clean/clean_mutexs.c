/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mutexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:23:35 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 11:08:49 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	clean_mutexs(t_global_data *shared)
{
	int		i;
	bool	state;

	i = 0;
	state = true;
	while (i < shared->parse_result.number_of_coder)
	{
		if (!shared->coders || !free_mutex(&shared->coders[i].mutex_coder))
			state = false;
		if (!shared->dongles || !free_mutex(&shared->dongles[i].mutex_dongle))
			state = false;
		i++;
	}
	if (!free_mutex(&shared->mutex_print))
		state = false;
	if (!free_mutex(&shared->mutex_is_run))
		state = false;
	return (state);
}
