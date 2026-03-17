/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:13:19 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/17 11:14:18 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include "enum.h"

typedef struct s_parsing_val
{
	int		number_of_coder;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles;
	int		dongle_cooldown;
	t_algo	scheduler;
}	t_parsing_val;

typedef struct s_dongle
{
	int				id;
	pthread_mutex_t	dongle;
}	t_dongle;

typedef struct s_coder
{
	int			id;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
}	t_coder;

typedef struct s_global_data
{
	t_coder		*list_coders;
	t_dongle	*list_dongles;
}	t_global_data;

#endif