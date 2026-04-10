/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:23:23 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 16:26:08 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	mutex_init(pthread_mutex_t	*mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		print_error("initializing a mutex fails");
		return (false);
	}
	return (true);
}
