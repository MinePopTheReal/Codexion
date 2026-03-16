/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:18:02 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/16 17:26:30 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../coders/codexion.h"

t_coder	*create_coders_list(t_dongle *list_dongles, int nb_coder)
{
	int		i;
	t_coder	*coders;

	i = 0;
	coders = malloc(nb_coder * sizeof(t_coder));
	if (!coders)
		return (NULL);
	while (i < nb_coder)
	{
		coders[i].id = i;
		coders[i].left_dongle = &list_dongles[i];
		if (i < nb_coder - 1)
			coders[i].right_dongle = &list_dongles[i + 1];
		else
			coders[i].right_dongle = &list_dongles[0];
		i++;
	}
	return (coders);
}

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
		dongles[i].id = i;
		i++;
	}
	return (dongles);
}
