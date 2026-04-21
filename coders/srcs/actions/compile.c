/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:03:28 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/08 17:03:28 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

bool	compile(t_coder *coder, t_dongle_order *dongle_order)
{
	long long int	compile_time;

	pthread_mutex_lock(&coder->mutex_coder);
	if (!print_state(coder->id, "is compiling", coder))
	{
		compile_time = coder->shared->parse_result.time_to_compile;
		pthread_mutex_unlock(&coder->mutex_coder);
		return (false);
	}
	coder->last_compile = get_curr_time_from_start();
	compile_time = coder->shared->parse_result.time_to_compile;
	pthread_mutex_unlock(&coder->mutex_coder);
	if (!smart_sleep(compile_time, coder))
		return (false);
	pthread_mutex_lock(&coder->mutex_coder);
	coder->nb_compiles += 1;
	pthread_mutex_unlock(&coder->mutex_coder);
	reorganize_queue(coder, dongle_order);
	return (true);
}
