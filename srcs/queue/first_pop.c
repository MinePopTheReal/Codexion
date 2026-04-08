/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/08 14:36:48 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

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
