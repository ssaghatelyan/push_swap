/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaghate <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:36:58 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/15 14:58:42 by ssaghate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index_from_stack(t_node *stack)
{
	t_node	*tmp;
	t_node	*cur;
	t_node	*min;
	int		idx;
	int		size;

	size = stack_size(stack);
	tmp = stack;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	idx = 0;
	while (idx < size)
	{
		min = NULL;
		cur = stack;
		while (cur)
		{
			if (cur->index == -1 && (!min || cur->value < min->value))
				min = cur;
			cur = cur->next;
		}
		if (min)
			min->index = idx++;
	}
}

// void	medium_sort(t_program *p)
// {
// 	int		size;
// 	int		chunk;
// 	int		i;
// 	int		j;
// 	t_node	*tmp;
// 	t_node	*max;

// 	size = stack_size(p->a);
// 	chunk = (int)sqrt((double)size);
// 	assign_index_from_stack(p->a);

// 	if (size <= 5)
// 	{
// 		sort_5(p);
// 		return ;
// 	}
	
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (p->a->index >= i && p->a->index < i + chunk)
// 				pb(p);
// 			else
// 				ra(p);
// 			j++;
// 		}
// 		i += chunk;
// 	}
// 	while (p->b)
// 	{
// 		max = p->b;
// 		tmp = p->b;
// 		while (tmp)
// 		{
// 			if (tmp->index > max->index)
// 				max = tmp;
// 			tmp = tmp->next;
// 		}
// 		while (p->b->index != max->index)
// 			ra(p);
// 		pa(p);
// 	}
// }

void	medium_sort(t_program *p)
{
	int		size;
	int		chunk;
	int		i;
	t_node	*tmp;
	t_node	*max;

	size = stack_size(p->a);
	chunk = (int)sqrt((double)size);
	assign_index_from_stack(p->a);

	if (size <= 5)
	{
		sort_5(p);
		return ;
	}

	i = 0;
	while (i < size)
	{
		while (p->a)
		{
    		if (p->a->index <= i)
			{
   		    	pb(p);
        		rb(p);
       		 i++;
   			}
    		else if (p->a->index <= i + chunk)
    		{
        		pb(p);
        		i++;
    		}
    		else
        		ra(p);
		}
		i += chunk;
	}
	while (p->b)
	{
		max = p->b;
		tmp = p->b;
		while (tmp)
		{
			if (tmp->index > max->index)
				max = tmp;
			tmp = tmp->next;
		}
		while (p->b->index != max->index)
			rb(p);
		pa(p);
	}
}