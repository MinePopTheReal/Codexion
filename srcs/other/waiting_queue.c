/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/06 14:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

t_waiting_queue	*new_node(void)
{
	t_waiting_queue	*new;

	new = malloc(sizeof(t_waiting_queue));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->coder = NULL;
	new->prev = NULL;
	return (new);
}

t_waiting_queue	*last_coder(t_waiting_queue *queue)
{
	t_waiting_queue	*temp;

	temp = queue;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	append_queue(t_waiting_queue **queue, t_coder *coder)
{
	t_waiting_queue	*new;
	t_waiting_queue	*last;

	new = new_node();
	if (!queue || !coder)
		return ;
	if (!new)
		return ;
	else if (*queue == NULL)
	{
		new->coder = coder;
		*queue = new;
	}
	else if (queue)
	{
		last = last_coder(*queue);
		last->next = new;
		new->prev = last;
		new->coder = coder;
	}
}

t_coder	*first_pop_queue(t_waiting_queue **queue)
{
	t_waiting_queue	*temp;
	t_coder			*coder;

	if (!queue || !*queue)
		return (NULL);
	temp = *queue;
	coder = temp->coder;
	*queue = temp->next;
	if (*queue)
		(*queue)->prev = NULL;
	free(temp);
	return (coder);
}

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
