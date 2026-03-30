/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:29:45 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/30 14:29:31 by tmalpert         ###   ########.fr       */
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

// print error
void			print_error(char *message);

//routine
void			*routine(void *ptr);
bool			compile(t_coder *coder);

//free
void			free_coders(t_global_data *global_data);

//monitor
void			*test_monitor(void *ptr);

//utils
long long int	get_curr_time_from_start(void);
bool			print_state(int coder_id, char *state, t_coder *coder);
bool			smart_sleep(long long int time_ms, t_coder *coder);



#endif