/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:00:59 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/13 14:46:51 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	is_valid_number(char *parse_value)
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
