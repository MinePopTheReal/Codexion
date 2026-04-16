/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:21:07 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/15 14:06:24 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	clean_sim(t_global_data *shared)
{
	bool	state;

	state = true;
	free_queues(shared);
	if (!free_mutex(shared))
		state = print_error("Mutex destruction failed.");
	free_entities(shared);
	return (state);
}
