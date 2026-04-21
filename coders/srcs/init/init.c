/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:23:29 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/20 23:56:35 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	init(t_global_data *shared)
{
	int		i;
	bool	state;

	i = 0;
	state = true;
	if (!shared_init(shared))
		state = false;
	while (i < shared->parse_result.number_of_coder)
	{
		if (!shared->coders || !mutex_init(&shared->coders[i].mutex_coder))
			state = false;
		if (!shared->dongles || !mutex_init(&shared->dongles[i].mutex_dongle))
			state = false;
		i++;
	}
	if (!mutex_init(&shared->mutex_print))
		state = false;
	if (!mutex_init(&shared->mutex_is_run))
		state = false;
	if (state == false || !init_queues(shared))
		state = false;
	return (state);
}
