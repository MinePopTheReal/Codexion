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
	t_coder			*coder;
	t_dongle_order	dongle_order;

	coder = (t_coder *) ptr;
	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = get_curr_time_from_start();
	pthread_mutex_unlock(&coder->mutex_coder);
	get_first_second(coder, &dongle_order);
	if (coder->id % 2 == 0)
		usleep(1500);
	if (dongle_order.second == dongle_order.first)
		return (NULL);
	while (true)
	{
		if ((coder->nb_compiles < \
coder->shared->parse_result.number_of_compiles))
			append_both(coder, &dongle_order);
		if (!is_done(coder))
			break ;
		if (!wait_dongle(coder, &dongle_order))
			break ;
		if (!actions(coder, &dongle_order))
			break ;
	}
	return (NULL);
}
