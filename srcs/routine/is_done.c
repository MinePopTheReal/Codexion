/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:33:22 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 16:36:28 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	is_done(t_coder *coder)
{
	bool	state;

	state = true;
	pthread_mutex_lock(&coder->mutex_coder);
	if (coder->nb_compiles >= coder->shared->parse_result.number_of_compiles)
		state = false;
	pthread_mutex_unlock(&coder->mutex_coder);
	return (state);
}
