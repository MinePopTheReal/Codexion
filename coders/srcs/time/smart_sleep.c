/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:36:07 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

bool	smart_sleep(long long int time_ms, t_coder *coder)
{
	long long int	time_count;
	long long int	start;

	time_count = 0;
	start = get_curr_time_from_start();
	time_count = get_curr_time_from_start();
	while (start + time_ms > time_count)
	{
		if (!get_is_run(coder))
			return (false);
		usleep(50);
		time_count = get_curr_time_from_start();
	}
	return (true);
}
