/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>          +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:03:47 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/08 17:03:47 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	debug(t_coder *coder)
{
	long long int	debug_time;

	if (!print_state("is debugging", coder))
		return (false);
	debug_time = coder->shared->parse_result.time_to_debug;
	if (!smart_sleep(debug_time, coder))
		return (false);
	return (true);
}
