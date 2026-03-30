/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:24:24 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/30 18:54:08 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"


void	*test_monitor(void *ptr)
{
	t_global_data	*shared;
	long long int	curr_us;
	// bool			is_run;
	int				i;

	// is_run = true;

	shared = (t_global_data *)ptr;
	while (true)
	{
		i = 0;
		while (i < shared->parse_result.number_of_coder - 1)
		{
			curr_us = get_curr_time_from_start();
			// printf("i: %d, curr: %lld, last: %lld\n", i, curr_us, shared->coders[i].last_compile);
			// printf("diff: %lld, lim: %d\n",curr_us - shared->coders[i].last_compile, shared->parse_result.time_to_burnout);
			pthread_mutex_lock(&shared->coders[i].mutex_coder);
			if (curr_us - shared->coders[i].last_compile >= shared->parse_result.time_to_burnout)
			{
				print_state(shared->coders[i].id, "burned out", &shared->coders[i]);
				pthread_mutex_lock(&shared->mutex_is_run);
				shared->is_run = false;
				pthread_mutex_unlock(&shared->mutex_is_run);
				return (NULL);
			}
			pthread_mutex_unlock(&shared->coders[i].mutex_coder);
			i++;
		}
	}
	return (NULL);
}
