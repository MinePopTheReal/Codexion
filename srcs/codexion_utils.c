/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:02:16 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/27 14:46:48 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

long long int	calculate_time(struct timeval s_time)
{
	long long int	time;

	time = s_time.tv_sec * 1000 + s_time.tv_usec / 1000;
	return (time);
}