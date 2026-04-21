/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 21:55:09 by tmalpert         ###   ########.fr       */
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
