/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:18:02 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/27 18:30:38 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../coders/types.h"
#include "../coders/prototypes.h" 

void	free_coders(t_global_data *global_data)
{
	free(global_data->dongles);
	free(global_data->coders);
}

t_coder	*create_coders_list(t_global_data *shared)
{
	int		i;
	t_coder	*coders;

	i = 0;
	coders = malloc(shared->parse_result.number_of_coder * sizeof(t_coder));
	if (!coders)
		return (NULL);
	while (i < shared->parse_result.number_of_coder)
	{
		coders[i].id = i;      
		coders[i].shared = shared;
		coders[i].left_dongle = &shared->dongles[i];
		if (i < shared->parse_result.number_of_coder - 1)
			coders[i].right_dongle = &shared->dongles[i + 1];
		else
			coders[i].right_dongle = &shared->dongles[0];
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
