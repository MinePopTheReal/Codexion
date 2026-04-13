/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:44:59 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 14:46:38 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"
#include "enum.h"

bool	parsing(int argc, char **argv, t_parsing *parse_value)
{
	int	i;

	i = 0;
	if (argc != 9)
	{
		print_error("some arguments are missing");
		return (false);
	}
	while (i < 8)
	{
		if (!is_valid_number(argv[i]))
			return (false);
		i++;
	}
	if (strcmp(argv[i], "fifo") == 0)
		parse_value->scheduler = ALGO_FIFO;
	else if (strcmp(argv[i], "edf") == 0)
		parse_value->scheduler = ALGO_EDF;
	else
	{
		print_error("you can only choose between 'edf' and 'fifo'");
		return (false);
	}
	set_value(argv, parse_value);
	return (true);
}
