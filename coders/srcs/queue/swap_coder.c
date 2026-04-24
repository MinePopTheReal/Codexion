/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_coder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:40:33 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

void	swap_coder(t_waiting_queue **queue)
{
	t_coder	*temp;

	temp = NULL;
	if (!queue || !*queue || !(*queue)->next)
		return ;
	if (priority((*queue)->coder, (*queue)->next->coder, \
&(*queue)->coder->shared->parse_result))
	{
		temp = (*queue)->coder;
		(*queue)->coder = (*queue)->next->coder;
		(*queue)->next->coder = temp;
	}
}
