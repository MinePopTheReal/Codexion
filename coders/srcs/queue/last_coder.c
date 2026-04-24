/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_coder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:41:17 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

t_waiting_queue	*last_coder(t_waiting_queue *queue)
{
	t_waiting_queue	*temp;

	temp = queue;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
