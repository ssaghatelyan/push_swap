/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:45:09 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/15 17:44:20 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_program	p;
	double		disorder;

	p.a = NULL;
	p.b = NULL;
	p.stats = (t_stats){0};

	if (argc < 2)
		return (0);

	parse_flags(argc, argv, &p.flags);
	parse_arguments(argc, argv, &p.a, p.flags.start);

	if (is_sorted(p.a))
	{
		if (&p.flags.bench)
			free_stack(&p.a);
		return (0);
	}

	disorder = compute_disorder(p.a);
	index_stack(p.a);

	if (p.flags.algo == SIMPLE)
		simple_sort(&p);
	else if (p.flags.algo == MEDIUM)
		medium_sort(&p);
	else if (p.flags.algo == COMPLEX)
		complex_sort(&p);
	else
		adaptive_sort(&p, disorder);
	if (p.flags.bench)
		print_bench(&p, disorder);

	free_stack(&p.a);
    return (0);
}