/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_loop_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 03:29:37 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

void	destroy_loop_mutex(t_global_data *shared, int i, int state)
{
	int	j;

	j = i - 1;
	while (--i >= 0)
	{
		if ((i == j && state > 4) || i < j)
			pthread_mutex_destroy(&shared->dongles[i].mutex_dongle);
		if ((i == j && state > 3) || i < j)
			pthread_mutex_destroy(&shared->coders[i].mutex_coder);
		if ((i == j && state > 2) || i < j)
			pthread_cond_destroy(&shared->dongles[i].cond_wait_dongle);
	}
}
