/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_time_from_start.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:37:06 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/09 23:37:11 by tmalpert         ###   ########.fr       */
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
