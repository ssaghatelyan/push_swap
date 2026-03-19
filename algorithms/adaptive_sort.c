/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaghate <ssaghate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:24:47 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/19 16:08:29 by ssaghate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_program *p, double disorder)
{
	int	size;

	size = stack_size(p->a);
	(void)disorder;
	if (size <= 5)
		simple_sort(p);
	else
		medium_sort(p);
}
