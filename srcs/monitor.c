/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:24:24 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/29 18:45:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"


void	*test_monitor(void *ptr)
{
	struct timeval	curr_time;
	t_global_data	*shared;
	long long int	curr_us;
	// bool			is_run;
	int				i;

	// is_run = true;

	shared = (t_global_data *)ptr;
	while (shared->is_run)
	{
		i = 0;
		while (i < shared->parse_result.number_of_coder - 1 && shared->is_run)
		{
			gettimeofday(&curr_time, NULL);
			curr_us = get_curr_time_from_start();
			// printf("i: %d, curr: %lld, last: %lld\n", i, curr_us, shared->coders[i].last_compile);
			// printf("diff: %lld, lim: %d\n",curr_us - shared->coders[i].last_compile, shared->parse_result.time_to_burnout);
			pthread_mutex_lock(&shared->coders[i].mutex_coder);
			if (curr_us - shared->coders[i].last_compile >= shared->parse_result.time_to_burnout)
			{
				print_state(i, "burned out");
				shared->is_run = false;
			}
			pthread_mutex_unlock(&shared->coders[i].mutex_coder);
			i++;
		}
	}
	return (NULL);
}
