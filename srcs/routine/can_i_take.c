/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_i_take.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:03:37 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/08 17:03:40 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	can_i_take(t_coder *coder, t_dongle *first, t_dongle *second)
{
	bool	i_can;

	i_can = true;
	pthread_mutex_lock(&first->mutex_dongle);
	pthread_mutex_lock(&second->mutex_dongle);
	pthread_mutex_lock(&coder->mutex_coder);
	coder->request_date = get_curr_time_from_start();
	pthread_mutex_unlock(&coder->mutex_coder);
	if (coder != first->waiting_queue->coder || \
coder != second->waiting_queue->coder || \
!check_cooldown(coder, first, second))
		i_can = false;
	pthread_mutex_unlock(&first->mutex_dongle);
	pthread_mutex_unlock(&second->mutex_dongle);
	return (i_can);
}