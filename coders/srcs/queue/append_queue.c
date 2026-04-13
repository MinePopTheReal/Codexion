/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 14:57:24 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

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
		if (coder->shared->parse_result.scheduler \
&& (*queue)->next == new \
&& priority((*queue)->coder, coder, &coder->shared->parse_result))
			swap_coder(queue);
	}
}
