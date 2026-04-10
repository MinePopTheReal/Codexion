/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:25:37 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 16:25:55 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	shared_init(t_global_data *shared)
{
	int	i;

	i = 0;
	shared->dongles = create_dongle_list(shared->parse_result.number_of_coder);
	shared->coders = create_coders_list(shared);
	shared->is_run = true;
	while (i < shared->parse_result.number_of_coder)
	{
		shared->dongles[i].waiting_queue = NULL;
		i++;
	}
	if (!shared->dongles || !shared->coders)
		return (false);
	return (true);
}
