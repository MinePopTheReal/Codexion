/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:45:06 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/18 13:24:12 by tmalpert         ###   ########.fr       */
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
		i++;
	}
	if (pthread_mutex_init((&shared->mutex_print), NULL) != 0)
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
	t_coder			*list_of_coder;

	list_of_coder = NULL;
	memset(&shared.parse_result, 0, sizeof(t_parsing));
	if (parsing(argc, argv, &shared.parse_result) == -1)
		return (-1);
	shared.dongles = create_dongle_list(shared.parse_result.number_of_coder);
	shared.coders = create_coders_list(&shared);
	if (init(&shared, shared.parse_result.number_of_coder) == -1)
		return (-1);

	i = 0;
	while (i < shared.parse_result.number_of_coder)
	{
		pthread_create(&shared.coders[i].thread_coder, NULL, &routine, &shared.coders[i]);
		i++;
	}
	i = 0;
	while (i < shared.parse_result.number_of_coder)
	{
		pthread_join(shared.coders[i].thread_coder, NULL);
		i++;
	}
	return (0);
}
