/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:04:54 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/16 10:11:30 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_program *p)
{
	if (p->a)
		free_stack(&p->a);
    if (p->b)
        free_stack(&p->b);
	write(2, "Error\n", 6);
	exit(1);
}

int parse_arguments(int argc, char **argv, t_program *p, int start)
{
    int i;
    int value;
    t_node *new;

    i = start;
    while (i < argc)
    {
        if (is_flag(argv[i]))
        {
            i++;
            continue;
        }
        if (!is_valid_number(argv[i]))
            error_exit(p);
        value = ft_atoi_safe(argv[i], p);
        new = new_node(value);
        if (!new)
            error_exit(p);
        add_back(&p->a, new);
        i++;
    }
    if (has_duplicates(p->a))
        error_exit(p);
    return (1);
}