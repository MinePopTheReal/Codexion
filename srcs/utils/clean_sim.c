/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:21:07 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 13:06:27 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	clean_sim(t_global_data *shared)
{
	free_entities(shared);
	free_queues(shared);
	if (!free_mutex(shared))
	{
		print_error("Mutex destruction failed.");
		return (false);
	}
	return (true);
}
