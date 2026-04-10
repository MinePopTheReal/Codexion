/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:54:43 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 16:12:33 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	is_finish(t_coder	*coder)
{
	bool	state;
	int		i;

	i = 0;
	state = true;
	if (coder->nb_compiles >= coder->shared->parse_result.number_of_compiles)
	{
		while (i < coder->shared->parse_result.number_of_coder)
		{
			if (coder->shared->coders[i].nb_compiles < \
coder->shared->parse_result.number_of_compiles)
				return (false);
			i++;
		}
		pthread_mutex_lock(&coder->shared->mutex_is_run);
		coder->shared->is_run = false;
		pthread_mutex_unlock(&coder->shared->mutex_is_run);
		return (true);
	}
	return (state);
}
