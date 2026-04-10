/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:26:59 by tmalpert          #+#    #+#             */
/*   Updated: 2026/04/10 16:27:33 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <stdio.h>

void	print_error(char *message)
{
	fprintf(stderr, "[" BOLD RED "ERROR" RESET "]: %s", message);
}
