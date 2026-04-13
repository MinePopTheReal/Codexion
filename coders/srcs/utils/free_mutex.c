/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:23:35 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 12:10:33 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	free_mutex(t_global_data *shared)
{
	int		i;
	bool	state;

	i = 0;
	state = true;
	while (i < shared->parse_result.number_of_coder)
	{
		if (pthread_mutex_destroy(&shared->coders[i].mutex_coder) != 0)
			state = false;
		if (pthread_mutex_destroy(&shared->dongles[i].mutex_dongle) != 0)
			state = false;
		i++;
	}
	if (pthread_mutex_destroy(&shared->mutex_print) != 0)
		state = false;
	if (pthread_mutex_destroy(&shared->mutex_is_run) != 0)
		state = false;
	if (pthread_mutex_destroy(&shared->mutex_global) != 0)
		state = false;
	return (state);
}
