/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:21:07 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 19:57:39 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

void	clean_sim(t_global_data *shared)
{
	clean_mutexs(shared);
	if (shared->coders)
		free(shared->coders);
	free_queues(shared);
	if (shared->dongles)
		free(shared->dongles);
}
