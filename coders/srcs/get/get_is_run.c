/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_is_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:38:09 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

bool	get_is_run(t_coder *coder)
{
	bool	state;

	pthread_mutex_lock(&coder->shared->mutex_is_run);
	state = coder->shared->is_run;
	pthread_mutex_unlock(&coder->shared->mutex_is_run);
	return (state);
}
