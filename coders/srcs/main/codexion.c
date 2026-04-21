/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:45:06 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 19:38:14 by tmalpert         ###   ########.fr       */
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
	clean_sim(&shared);
	return (state - 1);
}
