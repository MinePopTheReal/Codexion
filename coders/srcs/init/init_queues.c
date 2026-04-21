/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:10:56 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/20 20:29:40 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>

#include <types.h>

bool	init_queues(t_global_data *shared)
{
	int				i;
	int				parity;
	t_dongle_order	dongle_order;

	parity = 0;
	while (parity < 2)
	{
		i = 0;
		while (i < shared->parse_result.number_of_coder)
		{
			get_first_second(&shared->coders[i], &dongle_order);
			if (dongle_order.second == dongle_order.first)
				return (false);
			if (shared->coders[i].id % 2 == parity)
			{
				i++;
				continue ;
			}
			if (!append_both(&shared->coders[i], &dongle_order))
				return (false);
			i++;
		}
		parity++;
	}
	return (true);
}
