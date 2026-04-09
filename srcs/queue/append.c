/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/09 21:08:39 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

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

void	append_queue(t_waiting_queue **queue, t_coder *coder)
{
	t_waiting_queue	*new;
	t_waiting_queue	*last;
	t_coder			*temp;

	temp = NULL;
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
		
		if (coder->shared->parse_result.scheduler && (*queue)->next == new && priority((*queue)->coder, coder, &coder->shared->parse_result))
		{
			temp = (*queue)->coder;
			(*queue)->coder = coder;
			new->coder = temp;
		}
	}
}
