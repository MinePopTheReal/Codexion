/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:54:43 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 13:40:28 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	is_finish(t_coder	*coder)
{
	int		i;
	int		cpy_nb_compile_coder;

	i = 0;
	pthread_mutex_lock(&coder->mutex_coder);
	cpy_nb_compile_coder = coder->nb_compiles;
	pthread_mutex_unlock(&coder->mutex_coder);
	if (cpy_nb_compile_coder >= coder->shared->parse_result.number_of_compiles)
	{
		while (i < coder->shared->parse_result.number_of_coder)
		{
			pthread_mutex_lock(&coder->shared->coders[i].mutex_coder);
			if (coder->shared->coders[i].nb_compiles < \
coder->shared->parse_result.number_of_compiles)
			{
				pthread_mutex_unlock(&coder->shared->coders[i].mutex_coder);
				return (true);
			}
			pthread_mutex_unlock(&coder->shared->coders[i].mutex_coder);
			i++;
		}
		pthread_mutex_lock(&coder->shared->mutex_is_run);
		coder->shared->is_run = false;
		pthread_mutex_unlock(&coder->shared->mutex_is_run);
	}
	return (false);
}
