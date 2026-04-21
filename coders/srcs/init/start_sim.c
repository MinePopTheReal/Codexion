/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:22:56 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 16:10:46 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	start_sim(t_global_data *shared, t_monitor *monitor_data)
{
	int		nb_created;
	bool	state;

	state = true;
	nb_created = start_threads(shared, monitor_data);
	get_curr_time_from_start();
	pthread_mutex_lock(&shared->mutex_is_run);
	if (nb_created < shared->parse_result.number_of_coder)
	{
		state = print_error("An error occurred while creating the threads.");
		shared->is_run = false;
	}
	if (nb_created == -1)
	{
		pthread_mutex_unlock(&shared->mutex_is_run);
		return (false);
	}
	shared->sim_is_ready = true;
	pthread_mutex_unlock(&shared->mutex_is_run);
	join_threads(shared, monitor_data, nb_created);
	return (state);
}
