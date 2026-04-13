/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/07 16:59:15 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

void	free_queues(t_global_data *shared)
{
	int	i;

	i = 0;
	while (i < shared->parse_result.number_of_coder)
	{
		while (shared->dongles[i].waiting_queue)
			first_pop_queue(&shared->dongles[i].waiting_queue);
		i++;
	}
}
