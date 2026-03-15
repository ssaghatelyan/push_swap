/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:04:02 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/13 19:33:41 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_node **stack)
{
	t_node	*a;
	t_node	*b;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	a = *stack;
	b = a->next;
	a->next = b->next;
	b->next = a;
	*stack = b;
}

void	push_nodes(t_node **from, t_node **to)
{
	t_node	*n;

	if (!from || !*from)
		return ;
	n = *from;
	*from = n->next;
	n->next = *to;
	*to = n;
}

void	rotate_nodes(t_node **stack)
{
	t_node	*first;
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = first;
}

void	rev_rotate_nodes(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
