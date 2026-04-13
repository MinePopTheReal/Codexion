/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:45:06 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 13:13:51 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

int	main(int argc, char **argv)
{
	t_global_data	shared;
	t_monitor		monitor_data;

	memset(&shared.parse_result, 0, sizeof(t_parsing));
	if (!parsing(argc, argv, &shared.parse_result))
		return (-1);
	if (!init(&shared))
		return (-1);
	if (!start_thread(&shared, &monitor_data))
		return (-1);
	if (!join_thread(&shared, &monitor_data))
		return (-1);
	if (!clean_sim(&shared))
		return (-1);
	return (0);
}
