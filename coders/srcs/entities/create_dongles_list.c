/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dongles_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:48:13 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 02:51:12 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h" 

t_dongle	*create_dongle_list(t_global_data *shared)
{
	int			i;
	t_dongle	*dongles;

	i = 0;
	dongles = malloc(shared->parse_result.number_of_coder * sizeof(t_dongle));
	if (!dongles)
		return (NULL);
	while (i < shared->parse_result.number_of_coder)
	{
		dongles[i].release_time = -1;
		dongles[i].id = i + 1;
		dongles[i].waiting_queue = NULL;
		i++;
	}
	return (dongles);
}
