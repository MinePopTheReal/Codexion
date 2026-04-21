/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:23:29 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 22:08:21 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

int	init(t_global_data *shared)
{
	int	i;

	i = 0;
	if (!shared_init(shared))
		return (cleanup(shared, 1, i));
	while (i < shared->parse_result.number_of_coder)
	{
		if (!mutex_init(&shared->coders[i].mutex_coder))
			return (cleanup(shared, 2, i));
		if (!mutex_init(&shared->dongles[i].mutex_dongle))
		{
			pthread_mutex_destroy(&shared->coders[i].mutex_coder);
			return (cleanup(shared, 2, i));
		}
		i++;
	}
	if (!mutex_init(&shared->mutex_print))
		return (cleanup(shared, 3, i));
	if (!mutex_init(&shared->mutex_is_run))
		return (cleanup(shared, 4, i));
	if (!init_queues(shared))
		return (cleanup(shared, 5, i));
	return (true);
}
