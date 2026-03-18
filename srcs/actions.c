/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:46:22 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/18 11:15:34 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "prototypes.h"


void	*routine(void *ptr)
{
	t_coder	*coder;

	coder = (t_coder *) ptr;
	if (coder->id % 2 == 1)
		usleep(500);
	pthread_mutex_lock(&coder->left_dongle->mutex_dongle);
	coder->left_dongle->is_taken = true;
	pthread_mutex_lock((&coder->right_dongle->mutex_dongle));
	coder->right_dongle->is_taken = true;
	pthread_mutex_lock((&coder->shared->mutex_print));
	printf("Coder: %d, dongle stat:\nleft:\t%d\nright:\t%d\n\n",
		coder->id,
		coder->left_dongle->is_taken,
		coder->right_dongle->is_taken);
	usleep(1000000);
	pthread_mutex_unlock((&coder->shared->mutex_print));
	pthread_mutex_unlock((&coder->left_dongle->mutex_dongle));
	pthread_mutex_unlock((&coder->right_dongle->mutex_dongle));
	return (NULL);
}

void	compile(void)
{

}

void	debbug(void)
{

}

void	refactor(void)
{

}
