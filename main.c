/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:38:07 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/08 18:40:35 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;

    if (argc < 2)
        return (0);

    a = NULL;
    b = NULL;

    if (!parse_arguments(argc, argv, &a))
        return (1);

    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }

    index_stack(a);

    simple_sort(&a, &b);

    free_stack(&a);
    return (0);
}