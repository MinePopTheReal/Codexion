/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:25:37 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	shared_init(t_global_data *shared)
{
	int	i;

	i = 0;
	shared->dongles = create_dongle_list(shared);
	shared->coders = create_coders_list(shared);
	if (!shared->dongles || !shared->coders)
		return (false);
	shared->sim_is_ready = false;
	shared->is_run = true;
	return (true);
}
