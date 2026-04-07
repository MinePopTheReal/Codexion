/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:29:45 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/07 18:49:14 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

# include "types.h"

// init
t_dongle		*create_dongle_list(int nb_coder);
t_coder			*create_coders_list(t_global_data *shared);

// parsing
int				parsing(int argc, char **argv, t_parsing *parse_value);
void			print_error(char *message);

//actions
void			*routine(void *ptr);
bool	        debug(t_coder *coder);
bool	        refactor(t_coder *coder);
bool			compile(t_coder *coder);
bool	        actions(t_coder *coder, t_dongle *first, t_dongle *second);
bool            taken_dongles(t_coder *coder, t_dongle *first, t_dongle *second);
void            release_dongles(t_dongle *first, t_dongle *second);
void            get_first_second(t_coder *coder, t_dongle **first, t_dongle **second);
void	        append_both(t_coder *coder, t_dongle *first, t_dongle *second);
bool 	        is_done(t_coder *coder);
bool	        wait_dongle(t_coder *coder, t_dongle *first, t_dongle *second);
bool	        can_i_take(t_coder *coder, t_dongle *first, t_dongle *second);

//free
void			free_coders(t_global_data *global_data);

//monitor
void			*test_monitor(void *ptr);
bool	        sim_is_finish(t_global_data *shared);

//utils
long long int	get_curr_time_from_start(void);
bool			print_state(int coder_id, char *state, t_coder *coder);
bool			smart_sleep(long long int time_ms, t_coder *coder);

// waiting_queue
void			append_queue(t_waiting_queue **queue, t_coder *coder);
t_coder			*first_pop_queue(t_waiting_queue **queue);
void			free_queues(t_global_data *shared);
t_waiting_queue	*last_coder(t_waiting_queue *queue);
t_waiting_queue	*new_node(void);

#endif