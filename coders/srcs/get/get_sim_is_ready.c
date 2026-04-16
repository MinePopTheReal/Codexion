/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sim_is_ready.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:06:07 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/15 18:12:11 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

#include "types.h"

bool	get_sim_is_ready(t_global_data *shared)
{
	bool	state;

	pthread_mutex_lock(&shared->mutex_is_run);
	state = shared->sim_is_ready;
	pthread_mutex_unlock(&shared->mutex_is_run);
	return (state);
}
