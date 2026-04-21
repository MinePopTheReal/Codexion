/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coders_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:48:48 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 22:05:05 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h" 

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
		coders[i].id = i + 1;
		coders[i].shared = shared;
		coders[i].nb_compiles = 0;
		coders[i].last_compile = -1;
		coders[i].left_dongle = &shared->dongles[i];
		coders[i].right_dongle = &shared->dongles[(i + 1) \
% shared->parse_result.number_of_coder];
		i++;
	}
	return (coders);
}
