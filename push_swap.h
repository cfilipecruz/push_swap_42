/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:10:16 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/05 03:40:35 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>


typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE,
}					t_strategy;

typedef enum e_mode
{
	MODE_INVALID,
	MODE_BENCH
}					t_mode;

/* initialization.c */
int					exec_stack(int argc, char **argv, t_node **stack_a,
						t_node **stack_b);

/* args_handle.c */
int					is_flag(char *s);
int					is_valid_number(char *s);

/* stack_utils.c */
int					append_node(t_node **node, int value);
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);
int					has_duplicate(t_node *stack, int value);
t_node				*last_node(t_node *stack);

/* stack_utils_2.c */
int					get_max_pos(t_node *b);
void				set_ranks(t_node *stack_a, int *temp_ranks);
int					*get_ranks(t_node *stack_a, int size);

/* utils.c */
int					error_exit(t_node *stack_a, t_node *stack_b);
int					clean_exit(t_node *stack_a, t_node *stack_b);
void				print_error(void);
void				free_stack(t_node *stack);

/* math.c */
int					ft_sqrt(int n);

/* metrics.c */
double				compute_disorder(t_node *stack);

/* op_s.c */
int					sa(t_node *stack_a);
int					sb(t_node *stack_b);
int					ss(t_node *stack_a, t_node *stack_b);

/* op_p.c */
int					pa(t_node **stack_a, t_node **stack_b);
int					pb(t_node **stack_a, t_node **stack_b);

/* op_r.c */
int					ra(t_node **stack_a);
int					rb(t_node **stack_b);
int					rr(t_node **stack_a, t_node **stack_b);

/* op_rr.c */
int					rra(t_node **stack_a);
int					rrb(t_node **stack_b);
int					rrr(t_node **stack_a, t_node **stack_b);

/* algo_simple.c */
int					algo_simple(t_node **stack_a, t_node **stack_b);
void				pull_back_to_a(t_node **a, t_node **b);
void				push_cheapest_to_b(t_node **a, t_node **b);
void				sort_three(t_node **a);

/* algo_simple_exec.c */
int					max(int a, int b);
int					get_best_path(int *info, int *path);
void				exec_up(t_node **a, t_node **b, int p_a, int p_b);
void				exec_down(t_node **a, t_node **b, int p_a, int p_b);
void				execute_moves(t_node **a, t_node **b, int p_a, int p_b);

/* algo_simple_helpers.c */
int					get_min_pos(t_node *a);
int					get_target_a_pos(int val, t_node *a);
int					get_target_b_pos(int val, t_node *b);
int					get_cheapest_a_pos(t_node *a, t_node *b);

/* algo_medium.c */
int					algo_medium(t_node **stack_a, t_node **stack_b);

/* algo_complex.c */
int					algo_complex(t_node **stack_a, t_node **stack_b);

/* algo_adaptive.c */
int					algo_adaptive(t_node **stack_a, t_node **stack_b,
						double disorder);

/* benchmark.c */
void				benchmark(const char *move);
void				benchmark_start(double disorder, t_strategy strat);

/* temp_functions.c */
void				print_stack(t_node *stack);
#endif
