/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:23:29 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 03:37:32 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

int	init(t_global_data *shared)
{
	int	i;

	i = 0;
	if (!shared_init(shared))
		return (clean_init(shared, 1, i));
	while (i < shared->parse_result.number_of_coder)
	{
		if (pthread_cond_init(&shared->dongles[i].cond_wait_dongle, NULL) != 0)
			return (clean_init(shared, 2, i));
		if (!mutex_init(&shared->coders[i].mutex_coder))
			return (clean_init(shared, 3, i));
		if (!mutex_init(&shared->dongles[i].mutex_dongle))
			return (clean_init(shared, 4, i));
		i++;
	}
	if (!mutex_init(&shared->mutex_print))
		return (clean_init(shared, 5, i));
	if (!mutex_init(&shared->mutex_is_run))
		return (clean_init(shared, 6, i));
	if (!init_queues(shared))
		return (clean_init(shared, 7, i));
	return (true);
}
