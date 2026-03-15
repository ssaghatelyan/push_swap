/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:04:21 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/03 15:31:11 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	rotate_nodes(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate_nodes(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate_nodes(a);
	rotate_nodes(b);
	write(1, "rr\n", 3);
}
