/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:04:31 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/03 15:30:43 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	rev_rotate_nodes(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rev_rotate_nodes(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate_nodes(a);
	rev_rotate_nodes(b);
	write(1, "rrr\n", 4);
}
