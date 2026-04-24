/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorganize_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:47:31 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

void	reorganize_queue(t_coder *coder, t_dongle_order *dongle_order)
{
	if ((coder->nb_compiles < \
coder->shared->parse_result.number_of_compiles))
	{
		swap_coder(&dongle_order->first->waiting_queue);
		swap_coder(&dongle_order->second->waiting_queue);
	}
	else
	{
		first_pop_queue(&dongle_order->first->waiting_queue);
		first_pop_queue(&dongle_order->second->waiting_queue);
	}
}
