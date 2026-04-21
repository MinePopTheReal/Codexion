/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:34:25 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/21 11:13:54 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "types.h"

bool	priority(t_coder *first, t_coder *second, t_parsing	*parsing)
{
	bool			state;

	state = true;
	if (parsing->scheduler)
	{
		if (first->last_compile <= second->last_compile \
&& first->nb_compiles <= second->nb_compiles)
			state = false;
	}
	return (state);
}
