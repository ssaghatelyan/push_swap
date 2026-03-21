/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:24:02 by ssaghate          #+#    #+#             */
/*   Updated: 2026/03/21 14:44:12 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_program *p)
{
	if (p)
	{
		if (p->a)
			free_stack(&p->a);
		if (p->b)
			free_stack(&p->b);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	parse_arguments(int argc, char **argv, t_program *p, int start)
{
	int		i;
	int		j;
	int		value;
	char	**nums;

	i = start;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			i++;
			continue;
		}
		nums = ft_split(argv[i], ' ');
		if (!nums)
			error_exit(p);
		j = 0;
		while (nums[j])
		{
			if (is_flag(nums[j]))
			{
				handle_flag(nums[j], p);
				j++;
				continue;
			}
			if (!is_valid_number(nums[j], p))
				error_exit(p);
			value = ft_atoi_safe(nums[j], p);
			add_back(&p->a, new_node(value));
			j++;
		}
		free_split(nums);
		i++;
	}
	if (has_duplicates(p->a))
		error_exit(p);
}
