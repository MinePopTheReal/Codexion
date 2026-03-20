/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:44:59 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/17 17:35:24 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../coders/types.h"
#include "../coders/prototypes.h"
#include "../coders/enum.h"


static void	set_value(char **argv, t_parsing *parse_value)
{
	parse_value->number_of_coder = atoi(argv[1]);
	parse_value->time_to_burnout = atoi(argv[2]);
	parse_value->time_to_compile = atoi(argv[3]);
	parse_value->time_to_debug = atoi(argv[4]);
	parse_value->time_to_refactor = atoi(argv[5]);
	parse_value->number_of_compiles = atoi(argv[6]);
	parse_value->dongle_cooldown = atoi(argv[7]);
}

static bool	is_valid_number(char *parse_value)
{
	if (!parse_value)
	{
		print_error("only positive integers are allowed");
		return (false);
	}
	if (parse_value[0] == '-')
	{
		print_error("only positive integers are allowed");
		return (false);
	}
	return (true);
}

int	parsing(int argc, char **argv, t_parsing *parse_value)
{
	int	i;

	i = 0;
	if (argc != 9)
	{
		print_error("some arguments are missing");
		return (-1);
	}
	while (i < 8)
	{
		if (!is_valid_number(argv[i]))
			return (-1);
		i++;
	}
	if (strcmp(argv[i], "fifo") == 0)
		parse_value->scheduler = ALGO_FIFO;
	else if (strcmp(argv[i], "edf") == 0)
		parse_value->scheduler = ALGO_EDF;
	else
	{
		print_error("you can only choose between 'edf' and 'fifo'");
		return (-1);
	}
	set_value(argv, parse_value);
	return (0);
}
