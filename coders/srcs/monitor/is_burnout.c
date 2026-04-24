/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_burnout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:40:23 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 02:48:04 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

bool	is_burnout(t_coder *coder)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&coder->mutex_coder);
	if (get_curr_time_from_start() - coder->last_compile >= \
coder->shared->parse_result.time_to_burnout)
	{
		pthread_mutex_lock(&coder->shared->mutex_is_run);
		coder->shared->is_run = false;
		pthread_mutex_unlock(&coder->shared->mutex_is_run);
		print_state("burned out", coder);
		pthread_mutex_unlock(&coder->mutex_coder);
		while (i < coder->shared->parse_result.number_of_coder)
		{
			pthread_mutex_lock(\
&coder->shared->coders[i].right_dongle->mutex_dongle);
			pthread_cond_broadcast(\
&coder->shared->coders[i].right_dongle->cond_wait_dongle);
			pthread_mutex_unlock(\
&coder->shared->coders[i].right_dongle->mutex_dongle);
			pthread_mutex_lock(\
&coder->shared->coders[i].left_dongle->mutex_dongle);
			pthread_cond_broadcast(\
&coder->shared->coders[i].left_dongle->cond_wait_dongle);
			pthread_mutex_unlock(\
&coder->shared->coders[i].left_dongle->mutex_dongle);
			i++;
		}
		return (true);
	}
	pthread_mutex_unlock(&coder->mutex_coder);
	return (false);
}
