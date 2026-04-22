/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mutexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:23:35 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/23 02:02:12 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

void	clean_mutexs(t_global_data *shared)
{
	int		i;

	i = 0;
	while (i < shared->parse_result.number_of_coder)
	{
		if (shared->coders)
			pthread_mutex_destroy(&shared->coders[i].mutex_coder);
		if (shared->dongles)
		{
			pthread_cond_destroy(&shared->dongles[i].cond_wait_dongle);
			pthread_mutex_destroy(&shared->dongles[i].mutex_dongle);
		}
		i++;
	}
	pthread_mutex_destroy(&shared->mutex_is_run);
	pthread_mutex_destroy(&shared->mutex_print);
}
