/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:08:19 by marvin            #+#    #+#             */
/*   Updated: 2026/04/06 14:08:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>

#include <types.h>

bool	has_priority(t_waiting_queue **queue, t_parsing	*parsing)
{
	long long int	first_deadline;
	long long int	second_deadline;

	first_deadline = parsing->time_to_burnout + (*queue)->coder->last_compile - get_curr_time_from_start();
	second_deadline = parsing->time_to_burnout + (*queue)->next->coder->last_compile - get_curr_time_from_start(); 
	if (first_deadline < second_deadline)
		return (true);
	return (false);
}

void	add_queue(t_waiting_queue **queue, t_parsing *parsing)
{
	// edf
	if (parsing->scheduler)
	{
		if (has_priority(queue, parsing))
		{
			append_queue(queue, (*queue)->coder);
			rotate((*queue)->coder, queue);
		}
	}
	// fifo
	else
		append_queue(queue, (*queue)->coder);
}

void	*routine(void *ptr)
{
	t_coder		*coder;
	t_dongle	*first;
	t_dongle	*second;

	first = NULL;
	second = NULL;
	coder = (t_coder *) ptr;
	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = get_curr_time_from_start();
	pthread_mutex_unlock(&coder->mutex_coder);
	get_first_second(coder, &first, &second);
	if (coder->id % 2 == 0)
		usleep(50);
	if (second == first)
		return (NULL);
	// append_both(coder, first, second);
	while (true)
	{
		add_queue(&first->waiting_queue, &coder->shared->parse_result);
		add_queue(&second->waiting_queue, &coder->shared->parse_result);
		if (!is_done(coder))
			break ;
		if (!wait_dongle(coder, first, second))
			break ;
		if (!actions(coder, first, second))
			break ;
	}
	return (NULL);
}
