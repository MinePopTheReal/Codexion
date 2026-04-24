/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:20:50 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

void	join_threads(t_global_data *shared, t_monitor *monitor_data, \
int nb_created)
{
	int		i;

	i = -1;
	pthread_join(monitor_data->thread_monitor, NULL);
	while (++i < nb_created)
		pthread_join(shared->coders[i].thread_coder, NULL);
}
