/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:30:52 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/12 19:01:18 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_node **a, t_node **b)
{
	t_node	*min;
	int		pos;
	int		size;

	if (is_sorted(a))
		return ;
	size = stack_size(*a);
	if (size == 2)
	{
		sort_2(a);
		return ;
	}
	else if (size == 3)
	{
		sort_3(a);
		return ;
	}
	else
	{
		while (*a)
		{
			min = find_min(*a);
			pos = get_position(*a, min->value);
			rotate_to_top(a, pos);
			pb(a, b);
		}
	}
	while (*b)
		pa(a, b);
}
