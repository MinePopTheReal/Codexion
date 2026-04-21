/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:13:19 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 15:51:55 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include <stdbool.h> 
# include "enum.h"

struct	s_waiting_queue;
struct	s_global_data;
struct	s_coder;

struct s_parsing
{
	int						number_of_coder;
	int						time_to_burnout;
	int						time_to_compile;
	int						time_to_debug;
	int						time_to_refactor;
	int						number_of_compiles;
	int						dongle_cooldown;
	t_algo					scheduler;
};

struct s_dongle
{
	int						id;
	long long int			release_time;
	struct s_waiting_queue	*waiting_queue;
	pthread_mutex_t			mutex_dongle;
};

struct	s_waiting_queue
{
	struct s_coder			*coder;
	struct s_waiting_queue	*next;
	struct s_waiting_queue	*prev;
};

struct s_coder
{
	int						id;
	int						nb_compiles;
	long long int			last_compile;
	struct s_dongle			*left_dongle;
	struct s_dongle			*right_dongle;
	struct s_global_data	*shared;
	pthread_t				thread_coder;
	pthread_mutex_t			mutex_coder;
};

struct s_global_data
{
	bool					is_run;
	bool					sim_is_ready;
	struct s_coder			*coders;
	struct s_dongle			*dongles;
	struct s_parsing		parse_result;
	pthread_mutex_t			mutex_is_run;
	pthread_mutex_t			mutex_print;
};

struct s_monitor
{
	pthread_t				thread_monitor;
};

struct s_dongle_order
{
	struct s_dongle			*first;
	struct s_dongle			*second;
};

#endif