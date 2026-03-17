/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:29:45 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/17 11:08:30 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "structs.h"

t_dongle	*create_dongle_list(int nb_coder);
t_coder		*create_coders_list(t_dongle *list_dongles, int nb_coder);
int 		parsing(int argc, char **argv, t_parsing_val *parse_value);

#endif