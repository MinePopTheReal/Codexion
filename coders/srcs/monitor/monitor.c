/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:41 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/15 18:17:28 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

void	*monitor(void *ptr)
{
	t_global_data	*shared;
	int				i;

	shared = (t_global_data *)ptr;
	while (!get_sim_is_ready(shared))
		usleep(50);
	while (true)
	{
		i = 0;
		while (i < shared->parse_result.number_of_coder)
		{
			if (is_burnout(&shared->coders[i]))
				return (NULL);
			if (is_finish(&shared->coders[i]))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
