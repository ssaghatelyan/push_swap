/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:12:09 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/15 20:18:03 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stats
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_stats;

// typedef enum e_algo
// {
// 	SIMPLE,
// 	MEDIUM,
// 	COMPLEX,
// 	ADAPTIVE
// }	t_algo;

typedef struct s_flags
{
	// t_algo			algo;
	int				bench;
	int				SIMPLE;
	int				MEDIUM;
	int				COMPLEX;
	int				ADAPTIVE;
	int				start;
}	t_flags;

typedef struct s_program
{
	t_node	*a;
	t_node	*b;
	t_stats	stats;
	t_flags	flags;
}	t_program;

/* ===================== FLAGS ===================== */

int					is_flag(char *arg);
void				parse_flags(int argc, char **argv, t_flags *flags);

/* ===================== PARSING ===================== */

int					parse_arguments(int argc, char **argv, t_node **a, int start);
int					is_valid_number(char *str);
int					has_duplicates(t_node *a);

/* ===================== UTILS ===================== */

int					is_sorted(t_node *a);
void				index_stack(t_node *a);
t_node				*find_min(t_node *stack);
void				print_bench(t_program *p, double disorder);
int					get_position(t_node *stack, int value);
void				rotate_to_top(t_program *p, int pos);
int					total_operations(t_program *p);

/* ===================== STACK UTILS ===================== */

t_node				*new_node(int value);
void				add_back(t_node **stack, t_node *new);
int					stack_size(t_node *stack);
void				free_stack(t_node **stack);
int					ft_atoi_safe(char *str, t_node **a);

/* ===================== OPERATIONS ===================== */

void				swap_nodes(t_node **stack);
void				push_nodes(t_node **from, t_node **to);
void				rotate_nodes(t_node **stack);
void				rev_rotate_nodes(t_node **stack);

void				sa(t_program *p);
void				sb(t_program *p);
void				ss(t_program *p);

void				pa(t_program *p);
void				pb(t_program *p);

void				ra(t_program *p);
void				rb(t_program *p);
void				rr(t_program *p);

void				rra(t_program *p);
void				rrb(t_program *p);
void				rrr(t_program *p);

/* ===================== DISORDER ===================== */

double				compute_disorder(t_node *a);

/* ===================== ALGORITHMS ===================== */

void				simple_sort(t_program *p);
void				sort_2(t_program *p);
void				sort_3(t_program *p);
void				sort_5(t_program *p);
void				medium_sort(t_program *p);
void				complex_sort(t_program *p);
void				adaptive_sort(t_program *p, double disorder);

/* ===================== ERROR ===================== */

void				error_exit(t_node **a);

#endif
