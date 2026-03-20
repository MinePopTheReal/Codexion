/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:13:19 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/18 13:28:57 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include <stdbool.h> 
# include "enum.h"
# include <pthread.h> 

struct	s_global_data;
struct	s_parsing;
struct	s_dongle;
struct	s_coder;

struct s_parsing
{
	int		number_of_coder;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles;
	int		dongle_cooldown;
	t_algo	scheduler;
};

struct s_dongle
{
	int				id;
	bool			is_taken; // par forcement necessaire 
	pthread_mutex_t	mutex_dongle;
};

struct s_coder
{
	int						id;
	struct s_dongle			*left_dongle;
	struct s_dongle			*right_dongle;
	struct s_global_data	*shared;
	pthread_t				thread_coder;
};

struct s_global_data
{
	struct s_coder			*coders;
	struct s_dongle			*dongles;
	struct s_parsing		parse_result;
	pthread_mutex_t			mutex_print;
};

#endif