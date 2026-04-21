/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mutexs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:59:18 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 11:08:42 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

bool	free_mutex(pthread_mutex_t *mutex)
{
	bool	state;

	state = true;
	if (pthread_mutex_destroy(mutex) != 0)
		state = print_error("Mutex destruction failed.");
	return (state);
}
