/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:34:25 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/23 02:05:05 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

bool	priority(t_coder *first, t_coder *second, t_parsing	*parsing)
{
	bool			state;
	t_coder 		*r_first;
	t_coder 		*r_second;

	state = true;
	if (first > second)
	{
		r_first = first;
		r_second = second;
	}
	else
	{
		r_first = second;
		r_second = first;
	}
	if (parsing->scheduler)
	{
		pthread_mutex_lock(&r_first->mutex_coder);
		pthread_mutex_lock(&r_second->mutex_coder);
		if (r_first->last_compile <= r_second->last_compile \
&& r_first->nb_compiles <= r_second->nb_compiles)
			state = false;
		pthread_mutex_unlock(&r_first->mutex_coder);
		pthread_mutex_unlock(&r_second->mutex_coder);
	}
	return (state);
}
