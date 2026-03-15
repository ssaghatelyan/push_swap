/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:04:25 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/03 15:31:09 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	swap_nodes(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap_nodes(b);
	write(1, "sb\n", 3);
}
void	ss(t_node **a, t_node **b)
{
	swap_nodes(a);
	swap_nodes(b);
	write(1, "ss\n", 3);
}
