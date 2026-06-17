/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:10:16 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/17 17:08:14 by joavieir         ###   ########.fr       */
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

double				compute_disorder(t_node *stack);

int					is_flag(char *s);
int					is_valid_number(char *s);
int					has_duplicate(t_node *stack, int value);
int					append_node(t_node **node, int value);
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);
int					init_stack(int argc, char **argv, t_node **stack_a);
t_node				*last_node(t_node *stack);

int					error_exit(t_node *stack_a, t_node *stack_b);
int					clean_exit(t_node *stack_a, t_node *stack_b);
int					min_value(t_node *stack);
int					max_value(t_node *stack);
void				print_error(void);
void				free_stack(t_node *stack);

int				sa(t_node *stack_a);
int				sb(t_node *stack_b);
int				ss(t_node *stack_a, t_node *stack_b);

int				pa(t_node **stack_a, t_node **stack_b);
int				pb(t_node **stack_a, t_node **stack_b);

int				ra(t_node **stack_a);
int				rb(t_node **stack_b);
int				rr(t_node **stack_a, t_node **stack_b);

int				rra(t_node **stack_a);
int				rrb(t_node **stack_b);
int				rrr(t_node **stack_a, t_node **stack_b);

// Temp functions
void				print_stack(t_node *stack);
#endif
