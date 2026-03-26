/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaghate <ssaghate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:32:50 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/26 17:37:19 by ssaghate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(const char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
		if (*s < '0' || *s++ > '9')
			return (0);
	return (1);
}

static void	check_args(int argc, char **argv, t_program *p)
{
	long	num;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit(p);
		num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit(p);
		j = 1;
		while (j < i)
		{
			if (atoi(argv[j]) == (int)num)
				error_exit(p);
			j++;
		}
		i++;
	}
}

static void	execute_op_part2(char *line, t_program *p)
{
	if (!ft_strcmp(line, "ra\n"))
		ra(p);
	else if (!ft_strcmp(line, "rb\n"))
	{
		if (!p->b)
			error_exit(p);
		rb(p);
	}
	else if (!ft_strcmp(line, "rr\n"))
		rr(p);
	else if (!ft_strcmp(line, "rra\n"))
		rra(p);
	else if (!ft_strcmp(line, "rrb\n"))
	{
		if (!p->b)
			error_exit(p);
		rrb(p);
	}
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(p);
	else
		error_exit(p);
}

void	execute_op(char *line, t_program *p)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(p);
	else if (!ft_strcmp(line, "sb\n"))
	{
		if (!p->b)
			error_exit(p);
		sb(p);
	}
	else if (!ft_strcmp(line, "ss\n"))
		ss(p);
	else if (!ft_strcmp(line, "pa\n"))
	{
		if (!p->b)
			error_exit(p);
		pa(p);
	}
	else if (!ft_strcmp(line, "pb\n"))
	{
		if (!p->a)
			error_exit(p);
		pb(p);
	}
	else
		execute_op_part2(line, p);
}

int	main(int argc, char **argv)
{
	t_program	p;
	char		*line;

	ft_bzero(&p, sizeof(p));
	p.flags.checker_mode = 1;
	if (argc == 1)
		return (0);
	check_args(argc, argv, &p);
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
	return (0);
}
