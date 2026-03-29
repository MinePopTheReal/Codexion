/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:02:16 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/29 15:42:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

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

void	print_state(int coder_id, char *state)
{
	struct timeval	time;
	long long int	time_ms;

	gettimeofday(&time, NULL);
	time_ms = get_curr_time_from_start();
	printf("%lld %d %s\n", time_ms, coder_id, state);
}