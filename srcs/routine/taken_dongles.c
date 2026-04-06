/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:20:02 by marvin            #+#    #+#             */
/*   Updated: 2026/04/06 14:20:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	taken_dongles(t_coder *coder, t_dongle *first, t_dongle *second)
{
	if (!can_i_take(coder, first, second))
		return (false);
	pthread_mutex_lock(&first->mutex_dongle);
	if (!print_state(coder->id, "has taken a dongle", coder))
	{
		pthread_mutex_unlock(&first->mutex_dongle);
		return (false);
	}
	pthread_mutex_lock(&second->mutex_dongle);
	if (!print_state(coder->id, "has taken a dongle", coder))
	{
		release_dongles(first, second);
		return (false);
	}
	first_pop_queue(&first->waiting_queue);
	first_pop_queue(&second->waiting_queue);
	pthread_mutex_lock(&coder->mutex_coder);
	if ((coder->nb_compiles < coder->shared->parse_result.number_of_compiles - 1))
	{
		append_queue(&first->waiting_queue, coder);
		append_queue(&second->waiting_queue, coder);
	}
	pthread_mutex_unlock(&coder->mutex_coder);
	return (true);
}
