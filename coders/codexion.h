/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:29:45 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/16 17:07:19 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_parsing_val
{
	int		number_of_coder;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles;
	int		dongle_cooldown;
	char	*scheduler;
}	t_parsing_val;

typedef struct s_dongle
{
	int				id;
	pthread_mutex_t	dongle;

}	t_dongle;

typedef struct s_coder
{
	int			id; // peut etre pas necessaire
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
}	t_coder;

typedef struct s_global_data
{
	t_coder		*list_coders;
	t_dongle	*list_dongles;

}	t_global_data;

// void	*ft_calloc(size_t n, size_t size);
t_dongle	*create_dongle_list(int nb_coder);
t_coder		*create_coders_list(t_dongle *list_dongles, int nb_coder);
bool		parsing(int argc, char **argv, t_parsing_val *parse_value);

#endif