/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:41 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 15:25:23 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "structs.h"

void	*monitor(void *ptr)
{
	t_global_data	*shared;
	int				i;

	shared = (t_global_data *)ptr;
	while (true)
	{
		i = 0;
		while (i < shared->parse_result.number_of_coder)
		{
			pthread_mutex_lock(&shared->coders[i].mutex_coder);
			if (!is_burnout(&shared->coders[i]))
			{
				pthread_mutex_unlock(&shared->coders[i].mutex_coder);
				return (NULL);
			}
			if (!is_finish(&shared->coders[i]))
			{
				pthread_mutex_unlock(&shared->coders[i].mutex_coder);
				return (NULL);
			}
			pthread_mutex_unlock(&shared->coders[i].mutex_coder);
			i++;
		}
	}
	return (NULL);
}
