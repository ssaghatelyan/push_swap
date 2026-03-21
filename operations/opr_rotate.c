/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:04:21 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/21 16:12:25 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_program *p)
{
	rotate_nodes(&(p->a));
	p->stats.ra++;
	if (!p->flags.bench_mode)
		write(1, "ra\n", 3);
}

void	rb(t_program *p)
{
	rotate_nodes(&(p->b));
	p->stats.rb++;
	if (!p->flags.bench_mode)
		write(1, "rb\n", 3);
}

void	rr(t_program *p)
{
	rotate_nodes(&(p->a));
	rotate_nodes(&(p->b));
	p->stats.rr++;
	if (!p->flags.bench_mode)
		write(1, "rr\n", 3);
}
