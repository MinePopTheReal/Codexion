/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/20 14:05:02 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

bool	append_queue(t_waiting_queue **queue, t_coder *coder)
{
	t_waiting_queue	*new;
	t_waiting_queue	*last;

	new = new_node();
	if (!queue || !coder)
		return (false);
	if (!new)
		return (false);
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
	return (true);
}
