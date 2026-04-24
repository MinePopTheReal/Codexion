/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_one_dongle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 04:06:01 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

bool	take_one_dongle(t_coder *coder, t_dongle *dongle, struct timespec *ts)
{
	pthread_mutex_lock(&dongle->mutex_dongle);
	while ((coder != dongle->waiting_queue->coder) && get_is_run(coder))
		pthread_cond_wait(&dongle->cond_wait_dongle, &dongle->mutex_dongle);
	while (!check_cooldown(coder, dongle) && get_is_run(coder))
		pthread_cond_timedwait(&dongle->cond_wait_dongle, \
&dongle->mutex_dongle, ts);
	if (!print_state("has taken a dongle", coder))
		return (false);
	return (true);
}
