/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:10:16 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/11 23:29:11 by cmarques         ###   ########.fr       */
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
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}					t_strategy;

double				compute_disorder(t_node *stack);

int					is_flag(char *s);
int					is_valid_number(char *s);
int					has_duplicate(t_node *stack, int value);
int					append_node(t_node **node, int value);
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);

int					error_exit(t_node *stack_a, t_node *stack_b);
void				free_stack(t_node *stack);

void				sa(t_node *stack_a);
void				sb(t_node *stack_b);
void				ss(t_node *stack_a, t_node *stack_b);

void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);

void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);

void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

// Temp functions
void				print_stack(t_node *stack);
#endif
