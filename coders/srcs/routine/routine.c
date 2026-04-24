/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:08:19 by marvin            #+#    #+#             */
/*   Updated: 2026/04/06 14:08:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>

#include <types.h>

void	*routine(void *ptr)
{
	t_coder			*coder;
	t_dongle_order	dongle_order;

	coder = (t_coder *) ptr;
	if (!init_routine(coder, &dongle_order))
		return (NULL);
	while (true)
	{
		if (!is_done(coder))
			break ;
		if (!actions(coder, &dongle_order))
			break ;
	}
	return (NULL);
}
