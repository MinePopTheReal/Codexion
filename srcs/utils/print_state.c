/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:37:42 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/09 23:37:49 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

bool	print_state(int coder_id, char *state, t_coder *coder)
{
	long long int	time_ms;

	time_ms = get_curr_time_from_start();
	pthread_mutex_lock(&coder->shared->mutex_is_run);
	if (!coder->shared->is_run && strcmp(state, "burned out") != 0)
	{
		pthread_mutex_unlock(&coder->shared->mutex_is_run);
		return (false);
	}
	pthread_mutex_lock(&coder->shared->mutex_print);
	printf("%lld %d %s\n", time_ms, coder_id, state);
	pthread_mutex_unlock(&coder->shared->mutex_print);
	pthread_mutex_unlock(&coder->shared->mutex_is_run);
	return (true);
}
