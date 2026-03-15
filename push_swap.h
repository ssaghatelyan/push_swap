/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleksa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:12:09 by agaleksa          #+#    #+#             */
/*   Updated: 2026/03/12 19:03:22 by agaleksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

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

/* ===================== PARSING ===================== */

int					parse_arguments(int argc, char **argv, t_node **a);
int					is_valid_number(char *str);
int					has_duplicates(t_node *a);

/* ===================== UTILS ===================== */

int					is_sorted(t_node *a);
void				index_stack(t_node *a);
t_node				*find_min(t_node *stack);
int					get_position(t_node *stack, int value);
void				rotate_to_top(t_node **a, int pos);

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

void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);

void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);

void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);

void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

/* ===================== DISORDER ===================== */

double				compute_disorder(t_node *a);

/* ===================== ALGORITHMS ===================== */

void				simple_sort(t_node **a, t_node **b);
void				sort_2(t_node **a);
void				sort_3(t_node **a);
void				medium_sort(t_node **a, t_node **b);
void				complex_sort(t_node **a, t_node **b);
void				adaptive_sort(t_node **a, t_node **b);

/* ===================== ERROR ===================== */

void				error_exit(t_node **a);

#endif
