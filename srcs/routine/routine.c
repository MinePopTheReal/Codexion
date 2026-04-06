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
	append_both(coder, first, second);
	while (true)
	{
		if (!is_done(coder))
			break ;
		if (!wait_dongle(coder, first, second))
			break ;
		if (!actions(coder, first, second))
			break ;
	}
	return (NULL);
}