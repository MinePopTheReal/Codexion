/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:00:59 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/16 11:25:38 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

bool	is_valid_number(char **argv, int *temp)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (!argv[i])
			return (print_error("There can't be any NULL arguments."));
		temp[i] = ft_atoi(argv[i + 1]);
		if (temp[i] == -2)
			return (print_error("Only numbers, except for the scheduler."));
		if (temp[i] == -3)
			return (print_error("Too high value."));
		if (temp[i] == 0 && (i == 0 || i == 1))
			return (print_error("For the “number of coders” and “time to burnout” \
parameters, only numbers greater than zero are allowed."));
		if (temp[i] < 0)
			return (print_error("Only positive integers are allowed."));
		i++;
	}
	return (true);
}
