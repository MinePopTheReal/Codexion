/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:45:06 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/30 13:33:48 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../coders/types.h"
#include "../coders/colors.h"
#include "../coders/prototypes.h"


int	init(t_global_data *shared, int nb_coders)
{
	int	i;

	i = 0;
	while (i < nb_coders)
	{
		if (pthread_mutex_init((&shared->dongles[i].mutex_dongle), NULL) != 0)
		{
			print_error("initializing a mutex fails");
			return (-1);
		}
		if (pthread_mutex_init((&shared->coders[i].mutex_coder), NULL) != 0)
		{
			print_error("initializing a mutex fails");
			return (-1);
		}
		i++;
	}
	if (pthread_mutex_init((&shared->mutex_print), NULL) != 0)
	{
		print_error("initializing a mutex fails");
		return (-1);
	}
	if (pthread_mutex_init((&shared->mutex_is_run), NULL) != 0)
	{
		print_error("initializing a mutex fails");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv )
{
	int				i;
	t_global_data	shared;
	t_monitor		monitor;
	struct timeval	time;

	memset(&shared.parse_result, 0, sizeof(t_parsing));
	if (parsing(argc, argv, &shared.parse_result) == -1)
		return (-1);
	shared.dongles = create_dongle_list(shared.parse_result.number_of_coder);
	shared.coders = create_coders_list(&shared);
	shared.is_run = true;
	if (init(&shared, shared.parse_result.number_of_coder) == -1)
		return (-1);

	i = 0;
	while (i < shared.parse_result.number_of_coder)
	{
		gettimeofday(&time, NULL);
		pthread_mutex_lock(&shared.coders[i].mutex_coder);
		shared.coders[i].last_compile = get_curr_time_from_start();
		pthread_mutex_unlock(&shared.coders[i].mutex_coder);
		pthread_create(&shared.coders[i].thread_coder, NULL, &routine, &shared.coders[i]);
		i++;
	}
	pthread_create(&monitor.thread_monitor, NULL, &test_monitor, &shared);

	i = 0;
	pthread_join(monitor.thread_monitor, NULL);
	while (i < shared.parse_result.number_of_coder)
	{
		pthread_join(shared.coders[i].thread_coder, NULL);
		i++;
	}
	free_coders(&shared);
	return (0);
}
