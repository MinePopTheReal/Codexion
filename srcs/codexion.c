/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:45:06 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/16 17:28:07 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../coders/codexion.h"

int	main(int argc, char **argv )
{
	int				i;
	t_parsing_val	parse_values;
	t_global_data	global_data;
	t_coder			*list_of_coder;

	list_of_coder = NULL;
	memset(&parse_values, 0, sizeof(parse_values));
	if (!parsing(argc, argv, &parse_values))
		return (-1);
	global_data.list_dongles = create_dongle_list(parse_values.number_of_coder);
	global_data.list_coders = create_coders_list(
			global_data.list_dongles, parse_values.number_of_coder
			);
	// i = 0;
	// while (i < parse_values.number_of_coder)
	// {
	// 	printf("coder: %d have this dongle: left: %d, right: %d\n", 
	// 		global_data.list_coders[i].id,
	// 		global_data.list_coders[i].left_dongle->id,
	// 		global_data.list_coders[i].right_dongle->id);
	// 	i++;
	// }
	return (0);
}
