/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:27:02 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/08 17:29:57 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_to_top(t_node **a, int pos)
{
    int size;
    
    size = stack_size(*a);
    if(pos <= size / 2)
    {
        while (pos--)
            ra(a);
    }
    else
    {
        pos = size - pos;
        while (pos--)
            rra(a);
    }
}