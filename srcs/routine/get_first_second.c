/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:32:24 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 12:58:38 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prototypes.h>
#include <types.h>

void	get_first_second(t_coder *coder, t_dongle_order	*dongle_order)
{
	if (coder->left_dongle < coder->right_dongle)
	{
		dongle_order->first = coder->left_dongle;
		dongle_order->second = coder->right_dongle;
	}
	else
	{
		dongle_order->first = coder->right_dongle;
		dongle_order->second = coder->left_dongle;
	}
}
