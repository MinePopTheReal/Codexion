/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:08:30 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

bool	clean_init(t_global_data *shared, int state, int i)
{
	if (state >= 7)
		free_queues(shared);
	if (state > 6)
		pthread_mutex_destroy(&shared->mutex_is_run);
	if (state > 5)
		pthread_mutex_destroy(&shared->mutex_print);
	if (state >= 2)
		destroy_loop_mutex(shared, i, state);
	if (shared->coders && state >= 1)
		free(shared->coders);
	if (shared->dongles && state >= 1)
		free(shared->dongles);
	return (false);
}
