/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:23:29 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 13:13:30 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	init(t_global_data *shared)
{
	int	i;

	i = 0;
	if (!shared_init(shared))
		return (false);
	while (i < shared->parse_result.number_of_coder)
	{
		if (!mutex_init(&shared->dongles[i].mutex_dongle))
			return (false);
		if (!mutex_init(&shared->coders[i].mutex_coder))
			return (false);
		i++;
	}
	if (!mutex_init(&shared->mutex_print))
		return (false);
	if (!mutex_init(&shared->mutex_is_run))
		return (false);
	get_curr_time_from_start();
	return (true);
}
