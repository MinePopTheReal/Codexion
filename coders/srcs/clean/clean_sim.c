/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:21:07 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 11:24:04 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	clean_sim(t_global_data *shared)
{
	bool	state;

	state = false;
	if (!clean_mutexs(shared))
		state = false;
	if (shared->coders)
		free(shared->coders);
	free_queues(shared);
	if (shared->dongles)
		free(shared->dongles);
	return (state);
}
