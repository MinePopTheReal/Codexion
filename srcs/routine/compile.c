/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:20:02 by marvin            #+#    #+#             */
/*   Updated: 2026/04/06 14:20:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	compile(t_coder *coder)
{
	long long int	compile_time;
	bool			state;

	state = true;
	pthread_mutex_lock(&coder->mutex_coder);
	if (!print_state(coder->id, "is compiling", coder))
		return (false);
	coder->last_compile = get_curr_time_from_start();
	coder->nb_compiles += 1;
	compile_time = coder->shared->parse_result.time_to_compile;
	if (!smart_sleep(compile_time, coder))
		state = false;
	pthread_mutex_unlock(&coder->mutex_coder);
	return (state);
}