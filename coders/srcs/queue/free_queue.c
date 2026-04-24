/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:14 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

void	free_queues(t_global_data *shared)
{
	int				i;
	t_waiting_queue	*temp;

	i = 0;
	if (!shared->dongles)
		return ;
	while (i < shared->parse_result.number_of_coder && \
shared->dongles[i].waiting_queue)
	{
		while (shared->dongles[i].waiting_queue)
		{
			temp = shared->dongles[i].waiting_queue->next;
			free(shared->dongles[i].waiting_queue);
			shared->dongles[i].waiting_queue = temp;
		}
		i++;
	}
}
