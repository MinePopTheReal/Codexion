/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_burnout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:40:23 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/09 23:40:30 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

bool	is_burnout(t_coder *coder)
{
	if (get_curr_time_from_start() - coder->last_compile >= \
coder->shared->parse_result.time_to_burnout)
	{
		pthread_mutex_lock(&coder->shared->mutex_is_run);
		coder->shared->is_run = false;
		pthread_mutex_unlock(&coder->shared->mutex_is_run);
		print_state(coder->id, "burned out", coder);
		return (false);
	}
	return (true);
}
