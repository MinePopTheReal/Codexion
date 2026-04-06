/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:45:06 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/06 19:44:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../coders/types.h"
#include "../coders/colors.h"
#include "../coders/prototypes.h"

bool	mutex_init(pthread_mutex_t	*mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		print_error("initializing a mutex fails");
		return (false);
	}
	return (true);
}

bool	init(t_global_data *shared)
{
	int	i;

	i = 0;
	while (i < shared->parse_result.number_of_coder)
	{
		if (!mutex_init(&shared->dongles[i].mutex_dongle))
			return (false);
		if (!mutex_init(&shared->coders[i].mutex_coder))
			return (false);
		shared->dongles[i].waiting_queue = NULL;
		i++;
	}
	if (!mutex_init(&shared->mutex_print))
		return (false);
	if (!mutex_init(&shared->mutex_is_run))
		return (false);
	return (true);
}

int	main(int argc, char **argv )
{
	int				i;
	t_global_data	shared;
	t_monitor		monitor;

	memset(&shared.parse_result, 0, sizeof(t_parsing));
	if (parsing(argc, argv, &shared.parse_result) == -1)
		return (-1);
	shared.dongles = create_dongle_list(shared.parse_result.number_of_coder);
	shared.coders = create_coders_list(&shared);
	shared.is_run = true;
	if (!init(&shared))
		return (-1);
	i = 0;
	while (i < shared.parse_result.number_of_coder)
	{
		// shared.dongles[i].waiting_queue[0] = shared.coders[i];
		// shared.dongles[i].waiting_queue[1] = shared.coders[(shared.parse_result.number_of_coder + i - 1) % shared.parse_result.number_of_coder];
		// printf("%d : %d %d\n", shared.dongles[i].id, shared.dongles[i].waiting_queue[0].id, shared.dongles[i].waiting_queue[1].id);
		pthread_mutex_lock(&shared.coders[i].mutex_coder);
		shared.coders[i].last_compile = get_curr_time_from_start();
		pthread_mutex_unlock(&shared.coders[i].mutex_coder);
		pthread_create(&shared.coders[i].thread_coder, NULL, &routine, &shared.coders[i]);
		i++;
	}
	pthread_create(&monitor.thread_monitor, NULL, &test_monitor, &shared);
	pthread_join(monitor.thread_monitor, NULL);
	i = 0;
	while (i < shared.parse_result.number_of_coder)
	{
		pthread_join(shared.coders[i].thread_coder, NULL);
		i++;
	}
	free_coders(&shared);
	free_queues(&shared);
	return (0);
}
