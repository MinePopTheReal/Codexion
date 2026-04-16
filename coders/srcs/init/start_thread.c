/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:22:56 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/16 10:49:37 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	start_thread(t_global_data *shared, t_monitor *monitor_data)
{
	int	i;

	i = 0;
	while (i < shared->parse_result.number_of_coder)
	{
		if (pthread_create(&shared->coders[i].thread_coder, \
NULL, &routine, &shared->coders[i]) != 0)
			return (false);
		i++;
	}
	if (pthread_create(&monitor_data->thread_monitor, \
NULL, &monitor, shared) != 0)
		return (false);
	get_curr_time_from_start();
	pthread_mutex_lock(&shared->mutex_is_run);
	shared->sim_is_ready = true;
	pthread_mutex_unlock(&shared->mutex_is_run);
	return (true);
}
