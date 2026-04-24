/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:18:04 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "prototypes.h"

int	ft_atoi(const char *s)
{
	long long int	result;
	int				is_neg;

	result = 0;
	is_neg = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			is_neg *= -1;
		s++;
	}
	if (is_neg < 0)
		return (-1);
	while (*s)
	{
		if (ft_isdigit((int)*s) == 0)
			return (-2);
		if (is_neg == 1 && result > (LONG_MAX - (*s - '0')) / 10)
			return (-3);
		result = (result * 10) + (*s - '0');
		s++;
	}
	return (result * is_neg);
}
