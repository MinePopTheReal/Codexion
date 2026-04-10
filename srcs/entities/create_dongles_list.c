/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dongles_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:48:13 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 15:06:05 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h" 

t_dongle	*create_dongle_list(int nb_coder)
{
	int			i;
	t_dongle	*dongles;

	i = 0;
	dongles = malloc(nb_coder * sizeof(t_dongle));
	if (!dongles)
		return (NULL);
	while (i < nb_coder)
	{
		dongles[i].release_time = -1;
		dongles[i].id = i + 1;
		i++;
	}
	return (dongles);
}
