/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:37:03 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/15 21:11:09 by agaleksa         ###   ########.fr       */
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

void	parse_flags(int argc, char **argv, t_flags *flags)
{
	int i;

	flags->bench = 0;
    flags->SIMPLE = 0;
    flags->MEDIUM = 0;
    flags->COMPLEX = 0;
    flags->ADAPTIVE = 0;
	flags->start = 1;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--bench"))
			flags->bench = 1;
		else if (!ft_strcmp(argv[i], "--simple"))
		{
			if (flags->SIMPLE == 0 || flags->MEDIUM == 0 || flags->COMPLEX == 0
				|| flags->ADAPTIVE == 0)
				flags->SIMPLE = 1;
		}
		else if (!ft_strcmp(argv[i], "--medium"))
		{
			if (flags->SIMPLE == 0 || flags->MEDIUM == 0 || flags->COMPLEX == 0
				|| flags->ADAPTIVE == 0)
				flags->MEDIUM = 1;
		}
		else if (!ft_strcmp(argv[i], "--complex"))
		{
			if (flags->SIMPLE == 0 || flags->MEDIUM == 0 || flags->COMPLEX == 0
				|| flags->ADAPTIVE == 0)
				flags->COMPLEX = 1;
		}
		else if (!ft_strcmp(argv[i], "--adaptive"))
		{
			if (flags->SIMPLE == 0 || flags->MEDIUM == 0 || flags->COMPLEX == 0
				|| flags->ADAPTIVE == 0)
				flags->ADAPTIVE = 1;
		}
		i++;
	}
}