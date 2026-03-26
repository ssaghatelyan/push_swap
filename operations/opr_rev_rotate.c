/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaghate <ssaghate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:04:31 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/26 17:29:13 by ssaghate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_program *p)
{
	rev_rotate_nodes(&(p->a));
	p->stats.rra++;
	if (!p->flags.checker_mode)
		write(1, "rra\n", 4);
}

void	rrb(t_program *p)
{
	rev_rotate_nodes(&(p->b));
	p->stats.rrb++;
	if (!p->flags.checker_mode)
		write(1, "rrb\n", 4);
}

void	rrr(t_program *p)
{
	rev_rotate_nodes(&(p->a));
	rev_rotate_nodes(&(p->b));
	p->stats.rrr++;
	if (!p->flags.checker_mode)
		write(1, "rrr\n", 4);
}
