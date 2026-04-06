/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:24:24 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/02 18:45:59 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"


void	*test_monitor(void *ptr)
{
	t_global_data	*shared;
	long long int	curr_us;
	int				i;

	shared = (t_global_data *)ptr;
	while (true)
	{
		i = 0;
		while (i < shared->parse_result.number_of_coder - 1)
		{
			curr_us = get_curr_time_from_start();
			pthread_mutex_lock(&shared->coders[i].mutex_coder);
			if (curr_us - shared->coders[i].last_compile >= shared->parse_result.time_to_burnout)
			{
				print_state(shared->coders[i].id, "burned out", &shared->coders[i]);
				pthread_mutex_lock(&shared->mutex_is_run);
				shared->is_run = false;
				pthread_mutex_unlock(&shared->mutex_is_run);
				pthread_mutex_unlock(&shared->coders[i].mutex_coder);
				return (NULL);
			}
			pthread_mutex_unlock(&shared->coders[i].mutex_coder);
			i++;
		}
	}
	return (NULL);
}
