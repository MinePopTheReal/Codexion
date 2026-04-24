/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:44:59 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"
#include "enum.h"

bool	parsing(int argc, char **argv, t_parsing *parse_value)
{
	if (argc != 9)
		return (print_error("Argument are not valid (too many or not enough)"));
	if (strcmp(argv[8], "fifo") == 0)
		parse_value->scheduler = ALGO_FIFO;
	else if (strcmp(argv[8], "edf") == 0)
		parse_value->scheduler = ALGO_EDF;
	else
		return (print_error("You can only choose between 'edf' and 'fifo'"));
	if (!set_value(argv, parse_value))
		return (false);
	return (true);
}
