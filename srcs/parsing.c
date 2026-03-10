/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:44:59 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/10 17:35:08 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// number_of_coders 
// time_to_burnout 
// time_to_compile 
// time_to_debug 
// time_to_refactor 
// number_of_compiles_required 
// dongle_cooldown 
// scheduler

#include "codexion.h"

static void set_value(char **argv, t_parsing_val *parse_value)
{
	parse_value->number_of_coder = atoi(argv[1]);
	parse_value->time_to_burnout = atoi(argv[2]);
	parse_value->time_to_compile = atoi(argv[3]);
	parse_value->time_to_debug = atoi(argv[4]);
	parse_value->time_to_refactor = atoi(argv[5]);
	parse_value->number_of_compiles = atoi(argv[6]);
	parse_value->dongle_cooldown = atoi(argv[7]);
	parse_value->scheduler = argv[8];
}
static bool is_valid_number(char *parse_value)
{
	if (!parse_value)
		return (false);
	if (parse_value[0] == '-')
		return (false);
	return (true);
}

bool parsing(int argc, char **argv, t_parsing_val *parse_value)
{
	int i;

	i = 0;
	if (argc != 9)
		return (false);
	while (i < 8)
	{
		if (!is_valid_number(argv[i]))
			return (false);
		i++;
	}
	if (!(strcmp(argv[i], "fifo") == 0 || strcmp(argv[i], "edf") == 0))
		return (false);
	set_value(argv, parse_value);
	return (true);
}
