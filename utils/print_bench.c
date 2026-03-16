/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:05:32 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/16 10:19:27 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_operations(t_program *p)
{
	t_stats	*s;

	s = &p->stats;
	return (s->sa + s->sb + s->ss + s->pa + s->pb + s->ra + s->rb + s->rr
		+ s->rra + s->rrb + s->rrr);
}

void	print_bench(t_program *p, double disorder)
{
	t_stats	*s;
	char	*strategy;
	char	*complexity;
	int		whole;
	int		frac;

	s = &p->stats;
	if (p->flags.SIMPLE == 1 && p->flags.MEDIUM == 0 && p->flags.COMPLEX == 0
		&& p->flags.ADAPTIVE == 0)
		{
		strategy = "Simple";
		complexity = "O(n²)";
		}
	else if (p->flags.MEDIUM == 1 && p->flags.SIMPLE == 0
		&& p->flags.COMPLEX == 0 && p->flags.ADAPTIVE == 0)
		{
		strategy = "Medium";
		complexity = "O(n√n)";
		}
	else if (p->flags.COMPLEX == 1 && p->flags.SIMPLE == 0
		&& p->flags.MEDIUM == 0 && p->flags.ADAPTIVE == 0)
		{
		strategy = "Complex";
		complexity = "O(n log n)";
		}
	else
	{
		strategy = "Adaptive";	
			if (disorder < 0.2)
				complexity = "O(n²)";
			else if (disorder < 0.5)
				complexity = "O(n√n)";
			else
				complexity = "O(n log n)";
	}
	disorder *= 100;
	whole = (int)disorder;
	frac = (int)((disorder - whole) * 100);
		

	ft_printf("[bench] disorder: %d.%d%%\n", whole, frac);
	ft_printf("[bench] strategy: %s / %s\n", strategy, complexity);
	ft_printf("[bench] total_ops: %d\n", total_operations(p));
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", s->sa, s->sb,
		s->ss, s->pa, s->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", s->ra,
		s->rb, s->rr, s->rra, s->rrb, s->rrr);
}
