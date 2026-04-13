/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:00:41 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 14:47:00 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

void	set_value(char **argv, t_parsing *parse_value)
{
	parse_value->number_of_coder = atoi(argv[1]);
	parse_value->time_to_burnout = atoi(argv[2]);
	parse_value->time_to_compile = atoi(argv[3]);
	parse_value->time_to_debug = atoi(argv[4]);
	parse_value->time_to_refactor = atoi(argv[5]);
	parse_value->number_of_compiles = atoi(argv[6]);
	parse_value->dongle_cooldown = atoi(argv[7]);
}
