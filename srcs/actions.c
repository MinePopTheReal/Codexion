/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:46:22 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/27 18:58:14 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"

void	*routine(void *ptr)
{
	t_coder	*coder;
	// bool coder_is_run;
	struct timeval time;

	// coder_is_run = true;
	coder = (t_coder *) ptr;
	gettimeofday(&time, NULL);

	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = calculate_time(time);
	pthread_mutex_unlock(&coder->mutex_coder);
	while (coder->nb_compiles < coder->shared->parse_result.number_of_compiles)
	{
		if (coder->id % 2 == 1)
			usleep(500);
		// while 
		// Example of ordering by address
		t_dongle *first = (coder->left_dongle < coder->right_dongle) ? coder->left_dongle : coder->right_dongle;
		t_dongle *second = (coder->left_dongle < coder->right_dongle) ? coder->right_dongle : coder->left_dongle;
		pthread_mutex_lock(&first->mutex_dongle);
		pthread_mutex_lock(&second->mutex_dongle);
		coder->left_dongle->is_taken = true;
		coder->right_dongle->is_taken = true;
		pthread_mutex_lock((&coder->shared->mutex_print));
		printf("Coder: %d, dongle stat:\nleft:\t%d\nright:\t%d\n\n",
			coder->id,
			coder->left_dongle->is_taken,
			coder->right_dongle->is_taken);
		compile(coder);
		coder->left_dongle->is_taken = false;
		coder->right_dongle->is_taken = false;
		pthread_mutex_unlock((&coder->shared->mutex_print));
		pthread_mutex_unlock((&coder->left_dongle->mutex_dongle));
		pthread_mutex_unlock((&coder->right_dongle->mutex_dongle));
	}
	return (NULL);
}

void	compile(t_coder *coder)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&coder->mutex_coder);
	coder->last_compile = calculate_time(time);
	pthread_mutex_unlock(&coder->mutex_coder);
	coder->nb_compiles += 1;
	usleep(coder->shared->parse_result.time_to_compile * 1000); //petite opti possible
}

void	debbug(t_coder *coder)
{
	usleep(coder->shared->parse_result.time_to_compile);
}

void	refactor(t_coder *coder)
{
	usleep(coder->shared->parse_result.time_to_compile);
}
