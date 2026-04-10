/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:25:30 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 16:26:51 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	join_thread(t_global_data *shared, t_monitor *monitor_data)
{
	int	i;

	i = 0;
	pthread_join(monitor_data->thread_monitor, NULL);
	while (i < shared->parse_result.number_of_coder)
	{
		pthread_join(shared->coders[i].thread_coder, NULL);
		i++;
	}
	return (true);
}
