/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:37:35 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/11 16:37:38 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **a)
{
	int first;
	int second;
	int third;

	if (is_sorted(*a))
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	// 3 2 1
	if (first > second && second > third)
	{
		sa(a);  // 2 3 1
		rra(a); // 1 2 3
	}
	// 3 1 2
	else if (first > second && first > third && second < third)
		ra(a); // 1 2 3
	// 2 3 1
	else if (first < second && first > third)
		rra(a); // 1 2 3
	// 1 3 2
	else if (first < second && second > third && first < third)
	{
		sa(a); // 3 2 1
		ra(a); // 1 2 3
	}
	// 2 1 3
	else if (third > first && first > second)
		sa(a);
}