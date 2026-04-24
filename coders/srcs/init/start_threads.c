/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:19:43 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 03:57:05 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

int	start_threads(t_global_data *shared, t_monitor *monitor_data)
{
	int		nb_created;

	nb_created = 0;
	if (pthread_create(&monitor_data->thread_monitor, \
NULL, &monitor, shared) != 0)
		return (-1);
	while (nb_created < shared->parse_result.number_of_coder)
	{
		if (pthread_create(&shared->coders[nb_created].thread_coder, \
NULL, &routine, &shared->coders[nb_created]) != 0)
			break ;
		nb_created++;
	}
	return (nb_created);
}
