/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_dongles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:53:14 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/07 19:53:14 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>


void	rotate(t_coder *coder, t_waiting_queue **queue)
{
	first_pop_queue(queue);
	if ((coder->nb_compiles < \
coder->shared->parse_result.number_of_compiles - 1))
		append_queue(queue, coder);
}

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
		pthread_mutex_unlock(&first->mutex_dongle);
		pthread_mutex_unlock(&second->mutex_dongle);
		return (false);
	}
	pthread_mutex_lock(&coder->mutex_coder);
	rotate(coder, &first->waiting_queue);
	rotate(coder, &second->waiting_queue);
	pthread_mutex_unlock(&coder->mutex_coder);
	return (true);
}
