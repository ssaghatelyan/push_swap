/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:37:03 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/16 10:31:57 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *arg)
{
	if (!ft_strcmp(arg, "--bench"))
		return (1);
	if (!ft_strcmp(arg, "--simple"))
		return (1);
	if (!ft_strcmp(arg, "--medium"))
		return (1);
	if (!ft_strcmp(arg, "--complex"))
		return (1);
	if (!ft_strcmp(arg, "--adaptive"))
		return (1);
	return (0);
}

void	parse_flags(int argc, char **argv, t_program *p)
{
	int i;

	p->flags.bench = 0;
    p->flags.SIMPLE = 0;
    p->flags.MEDIUM = 0;
    p->flags.COMPLEX = 0;
    p->flags.ADAPTIVE = 0;
	p->flags.start = 1;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--bench"))
		{
			if (p->flags.bench == 0)
				p->flags.bench = 1;
			else
				error_exit(p);
		}
		else if (!ft_strcmp(argv[i], "--simple"))
		{
			if (p->flags.SIMPLE == 0 && p->flags.MEDIUM == 0 && p->flags.COMPLEX == 0
				&& p->flags.ADAPTIVE == 0)
				p->flags.SIMPLE = 1;
			else 
				error_exit (p);
		}
		else if (!ft_strcmp(argv[i], "--medium"))
		{
			if (p->flags.SIMPLE == 0 && p->flags.MEDIUM == 0 && p->flags.COMPLEX == 0
				&& p->flags.ADAPTIVE == 0)
				p->flags.MEDIUM = 1;
			else
				error_exit(p);
		}
		else if (!ft_strcmp(argv[i], "--complex"))
		{
			if (p->flags.SIMPLE == 0 && p->flags.MEDIUM == 0 && p->flags.COMPLEX == 0
				&& p->flags.ADAPTIVE == 0)
				p->flags.COMPLEX = 1;
			else
				error_exit(p);
		}
		else if (!ft_strcmp(argv[i], "--adaptive"))
		{
			if (p->flags.SIMPLE == 0 && p->flags.MEDIUM == 0 && p->flags.COMPLEX == 0
				&& p->flags.ADAPTIVE == 0)
				p->flags.ADAPTIVE = 1;
			else
				error_exit(p);
		}
		else
			p->flags.ADAPTIVE = 1;
		i++;
	}
}