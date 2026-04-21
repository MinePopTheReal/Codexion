/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:26 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 22:13:32 by tmalpert         ###   ########.fr       */
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
void			clean_sim(t_global_data *shared);
void			clean_mutexs(t_global_data *shared);
bool			free_mutex(pthread_mutex_t *mutex);
int				cleanup(t_global_data *shared, int state, int i);

// entities
t_dongle		*create_dongle_list(t_global_data *shared);
t_coder			*create_coders_list(t_global_data *shared);

// get
bool			get_is_run(t_coder *coder);
bool			get_sim_is_ready(t_global_data *shared);

// monitor
void			*monitor(void *ptr);
bool			is_burnout(t_coder *coder);
bool			is_finish(t_coder *coder);

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

// parsing
int				ft_isdigit(int c);
int				ft_atoi(const char *s);
bool			is_valid_number(char **argv, int *temp);
bool			set_value(char **argv, t_parsing *parse_value);
bool			parsing(int argc, char **argv, t_parsing *parse_value);

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
bool			can_i_take(t_coder *coder, t_dongle_order *dongle_order);
bool			wait_dongle(t_coder *coder, t_dongle_order *dongle_order);
bool			take_dongles(t_coder *coder, t_dongle_order *dongle_order);
bool			check_cooldown(t_coder *coder, t_dongle_order *dongle_order);
void			get_first_second(t_coder *coder, t_dongle_order	*dongle_order);

// time
long long int	get_curr_time_from_start(void);
bool			smart_sleep(long long int time_ms, t_coder *coder);

// print
bool			print_error(char *message);
bool			print_state(int coder_id, char *state, t_coder *coder);

#endif