/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_coder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:40:33 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 16:45:49 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

void	swap_coder(t_waiting_queue **queue)
{
	t_coder	*temp;

	temp = NULL;
	temp = (*queue)->coder;
	(*queue)->coder = (*queue)->next->coder;
	(*queue)->next->coder = temp;
}
