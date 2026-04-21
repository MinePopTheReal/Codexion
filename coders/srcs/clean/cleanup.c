/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:08:30 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 22:08:57 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

int	cleanup(t_global_data *shared, int state, int i)
{
	if (state > 5)
		free_queues(shared);
	if (state > 4)
		pthread_mutex_destroy(&shared->mutex_is_run);
	if (state > 3)
		pthread_mutex_destroy(&shared->mutex_print);
	if (state >= 2)
	{
		while (--i >= 0)
		{
			pthread_mutex_destroy(&shared->coders[i].mutex_coder);
			pthread_mutex_destroy(&shared->dongles[i].mutex_dongle);
		}
	}
	if (state >= 1)
	{
		free(shared->coders);
		free(shared->dongles);
	}
	return (false);
}
