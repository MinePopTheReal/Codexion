/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:26 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/24 17:55:01 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include "types.h"

// actions
bool			debug(t_coder *coder);
bool			refactor(t_coder *coder);
bool			actions(t_coder *coder, t_dongle_order *dongle_order);
bool			compile(t_coder *coder, t_dongle_order *dongle_order);

// clean
bool			clean_init(t_global_data *shared, int state, int i);
void			destroy_loop_mutex(t_global_data *shared, int i, int state);

// entities
t_dongle		*create_dongle_list(t_global_data *shared);
t_coder			*create_coders_list(t_global_data *shared);

// get
bool			get_is_run(t_coder *coder);
bool			get_sim_is_ready(t_global_data *shared);

// init
int				init(t_global_data *shared);
bool			init_queues(t_global_data *shared);
bool			shared_init(t_global_data *shared);
bool			mutex_init(pthread_mutex_t	*mutex);
bool			start_sim(t_global_data *shared, t_monitor *monitor_data);
bool			init_routine(t_coder *coder, t_dongle_order *dongle_order);
int				start_threads(t_global_data *shared, t_monitor *monitor_data);
void			join_threads(t_global_data *shared, t_monitor *monitor_data, \
int nb_created);

// monitor
void			*monitor(void *ptr);
bool			is_burnout(t_coder *coder);
bool			is_finish(t_coder *coder);

// parsing
int				ft_isdigit(int c);
int				ft_atoi(const char *s);
bool			is_valid_number(char **argv, int *temp);
bool			set_value(char **argv, t_parsing *parse_value);
bool			parsing(int argc, char **argv, t_parsing *parse_value);

// print
bool			print_error(char *message);
bool			print_state(char *state, t_coder *coder);

// queue
t_waiting_queue	*new_node(void);
void			free_queues(t_global_data *shared);
void			swap_coder(t_waiting_queue **queue);
t_waiting_queue	*last_coder(t_waiting_queue *queue);
t_coder			*first_pop_queue(t_waiting_queue **queue);
bool			append_queue(t_waiting_queue **queue, t_coder *coder);
bool			append_both(t_coder *coder, t_dongle_order *dongle_order);
bool			priority(t_coder *first, t_coder *second, t_parsing *parsing);
void			reorganize_queue(t_coder *coder, t_dongle_order *dongle_order);

// routine
void			*routine(void *ptr);
bool			is_done(t_coder *coder);
void			release_dongles(t_dongle_order *dongle_order);
bool			check_cooldown(t_coder *coder, t_dongle *dongle);
bool			take_two_dongles(t_coder *coder, t_dongle_order *dongle_order);
void			get_first_second(t_coder *coder, t_dongle_order	*dongle_order);
bool			take_one_dongle(t_coder *coder, t_dongle *dongle, \
struct timespec *ts);

// time
long long int	get_curr_time_from_start(void);
struct timespec	calcul_timespec(t_global_data *shared);
bool			smart_sleep(long long int time_ms, t_coder *coder);

#endif