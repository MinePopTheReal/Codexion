/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:02:16 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/06 14:12:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

bool	get_is_run(t_coder *coder)
{
	bool	is_run;

	pthread_mutex_lock(&coder->shared->mutex_is_run);
	is_run = coder->shared->is_run;
	pthread_mutex_unlock(&coder->shared->mutex_is_run);
	return (is_run);
}

long long int	get_curr_time_from_start(void)
{
	struct timeval			s_time;
	long long int			curr_time_ms;
	static long long int	start_time_ms = -1;

	gettimeofday(&s_time, NULL);
	curr_time_ms = s_time.tv_sec * 1000 + s_time.tv_usec / 1000;
	if (start_time_ms == -1)
		start_time_ms = curr_time_ms;
	return (curr_time_ms - start_time_ms);
}

bool	print_state(int coder_id, char *state, t_coder *coder)
{
	long long int	time_ms;
	bool			cpy_is_run;

	cpy_is_run = get_is_run(coder);
	time_ms = get_curr_time_from_start();
	if (!cpy_is_run)
		return (false);
	pthread_mutex_lock(&coder->shared->mutex_print);
	printf("%lld %d %s\n", time_ms, coder_id, state);
	pthread_mutex_unlock(&coder->shared->mutex_print);
	return (true);
}

bool	smart_sleep(long long int time_ms, t_coder *coder)
{
	int				step;
	long long int	time_count_ms;
	long long int	start;

	step = 50;
	time_count_ms = 0;
	start = get_curr_time_from_start();
	time_count_ms = get_curr_time_from_start();
	while (start + time_ms > time_count_ms)
	{
		if (!get_is_run(coder))
			return (false);
		else if (time_ms - time_count_ms < step)
			step = time_ms - time_count_ms;
		usleep(500);
		time_count_ms = get_curr_time_from_start();
	}
	return (true);
}
