/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:00:41 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/16 11:03:52 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	set_value(char **argv, t_parsing *parse_value)
{
	int	temp[7];

	if (!is_valid_number(argv, temp))
		return (false);
	parse_value->number_of_coder = temp[0];
	parse_value->time_to_burnout = temp[1];
	parse_value->time_to_compile = temp[2];
	parse_value->time_to_debug = temp[3];
	parse_value->time_to_refactor = temp[4];
	parse_value->number_of_compiles = temp[5];
	parse_value->dongle_cooldown = temp[6];
	return (true);
}
