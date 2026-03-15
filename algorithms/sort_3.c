/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:37:35 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/13 21:45:50 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_program *p)
{
	int first;
	int second;
	int third;

	if (is_sorted(p->a))
		return ;
	first = (p->a)->value;
	second = (p->a)->next->value;
	third = (p->a)->next->next->value;
	// 3 2 1
	if (first > second && second > third)
	{
		sa(p);  // 2 3 1
		rra(p); // 1 2 3
	}
	// 3 1 2
	else if (first > second && first > third && second < third)
		ra(p); // 1 2 3
	// 2 3 1
	else if (first < second && first > third)
		rra(p); // 1 2 3
	// 1 3 2
	else if (first < second && second > third && first < third)
	{
		sa(p); // 3 2 1
		ra(p); // 1 2 3
	}
	// 2 1 3
	else if (third > first && first > second)
		sa(p);
}