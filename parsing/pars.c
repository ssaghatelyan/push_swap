/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:04:54 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/08 18:20:56 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_node **a)
{
	if (a)
		free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

int parse_arguments(int argc, char **argv, t_node **a)
{
    int     i;
    int     value;
    t_node  *new;

    i = 1;
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
            error_exit(a);
        value = ft_atoi_safe(argv[i], a);
        new = new_node(value);
        if (!new)
            error_exit(a);
        add_back(a, new);
        i++;
    }
    if (has_duplicates(*a))
        error_exit(a);
    return (1);
}