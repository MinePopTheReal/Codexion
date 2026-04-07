/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:41 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/07 19:51:47 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

bool	is_finish(t_coder	*coder)
{
	bool	state;

	state = true;
	if (coder->nb_compiles >= coder->shared->parse_result.number_of_compiles)
	{
		if (sim_is_finish(coder->shared))
		{
			pthread_mutex_lock(&coder->shared->mutex_is_run);
			coder->shared->is_run = false;
			pthread_mutex_unlock(&coder->shared->mutex_is_run);
			state = false;
		}
	}
	return (state);
}

bool	is_burnout(t_coder *coder)
{
	bool	state;

	state = true;
	if (get_curr_time_from_start() - coder->last_compile >= \
coder->shared->parse_result.time_to_burnout)
	{
		print_state(coder->id, "burned out", coder);
		pthread_mutex_lock(&coder->shared->mutex_is_run);
		coder->shared->is_run = false;
		pthread_mutex_unlock(&coder->shared->mutex_is_run);
		state = false;
	}
	return (state);
}

void	*test_monitor(void *ptr)
{
	t_global_data	*shared;
	int				i;

	shared = (t_global_data *)ptr;
	while (true)
	{
		i = 0;
		while (i < shared->parse_result.number_of_coder)
		{
			pthread_mutex_lock(&shared->coders[i].mutex_coder);
			if (!is_burnout(&shared->coders[i]))
			{
				pthread_mutex_unlock(&shared->coders[i].mutex_coder);
				return (NULL);
			}
			if (!is_finish(&shared->coders[i]))
			{
				pthread_mutex_unlock(&shared->coders[i].mutex_coder);
				return (NULL);
			}
			pthread_mutex_unlock(&shared->coders[i].mutex_coder);
			i++;
		}
	}
	return (NULL);
}
