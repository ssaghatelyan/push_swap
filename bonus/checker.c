/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaghate <ssaghate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:32:50 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/21 16:42:52 by ssaghate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_op(char *line, t_program *p)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(p);
	else if (!ft_strcmp(line, "sb\n"))
		sb(p);
	else if (!ft_strcmp(line, "ss\n"))
		ss(p);
	else if (!ft_strcmp(line, "pa\n"))
		pa(p);
	else if (!ft_strcmp(line, "pb\n"))
		pb(p);
	else if (!ft_strcmp(line, "ra\n"))
		ra(p);
	else if (!ft_strcmp(line, "rb\n"))
		rb(p);
	else if (!ft_strcmp(line, "rr\n"))
		rr(p);
	else if (!ft_strcmp(line, "rra\n"))
		rra(p);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(p);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(p);
	else
		error_exit(p);
}

int	main(int argc, char **argv)
{
	t_program	p;
	char		*line;

	ft_bzero(&p, sizeof(p));
	p.flags.checker_mode = 1;
	parse_arguments(argc, argv, &p, 1);
	line = get_next_line(0);
	while (line)
	{
		execute_op(line, &p);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(p.a) && !p.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&p.a);
	free_stack(&p.b);
}
