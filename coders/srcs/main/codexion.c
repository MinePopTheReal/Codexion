/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:45:06 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

int	main(int argc, char **argv)
{
	bool			state;
	t_global_data	shared;
	t_monitor		monitor_data;

	state = true;
	memset(&shared.parse_result, 0, sizeof(t_parsing));
	if (!parsing(argc, argv, &shared.parse_result))
		return (false);
	if (!init(&shared))
		return (false);
	if (!start_sim(&shared, &monitor_data))
		state = false;
	clean_init(&shared, 7, shared.parse_result.number_of_coder - 1);
	return (state - 1);
}
