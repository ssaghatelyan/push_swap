/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:37:05 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/16 18:35:02 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_node *stack)
{
	int		max = 0;
	int		bits = 0;
	t_node	*tmp = stack;

	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_program *p)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(p->a);
	max_bits = get_max_bits(p->a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((p->a->index >> i) & 1) == 1)
				ra(p);
			else
				pb(p);
			j++;
		}
		while (p->b)
			pa(p);
		i++;
	}
}

int	cmp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void	assign_index(t_node *stack, int *sorted, int size)
{
	t_node	*tmp;
	int		i;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == sorted[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	complex_sort(t_program *p)
{
	int		size;
	int		*sorted;
	t_node	*tmp;
	int		i;

	size = stack_size(p->a);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		error_exit(p);
	tmp = p->a;
	i = 0;
	while (tmp)
	{
		sorted[i++] = tmp->value;
		tmp = tmp->next;
	}
	qsort(sorted, size, sizeof(int), cmp_int);
	assign_index(p->a, sorted, size);
	radix_sort(p);
	free(sorted);
}