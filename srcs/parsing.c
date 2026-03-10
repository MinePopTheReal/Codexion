/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:44:59 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/10 14:16:50 by tmalpert         ###   ########.fr       */
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

static int is_valid_number(char *parse_value)
{
	int value;

	if (!parse_value)
		return (-1);
	value = atoi(parse_value);
	if (value <= 0)
		return (-1);
	return (value);
}

t_parsing_val parsing(int argc, char **argv)
{
	t_parsing_val parse_value;

	memset(&parse_value, 0, sizeof(parse_value));
	if (argc != 9)
		return (parse_value);
	parse_value.number_of_coder = is_valid_number(argv[1]);
	parse_value.time_to_burnout = is_valid_number(argv[2]);
	parse_value.time_to_compile = is_valid_number(argv[3]);
	parse_value.time_to_debug = is_valid_number(argv[4]);
	parse_value.time_to_refactor = is_valid_number(argv[5]);
	parse_value.number_of_compiles = is_valid_number(argv[6]);
	parse_value.dongle_cooldown = is_valid_number(argv[7]);
	if (strcmp(argv[8], "fifo") || strcmp(argv[8], "edf"))
		parse_value.scheduler = argv[8];
	return (parse_value);
}
