/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:10:16 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/10 17:57:54 by cmarques         ###   ########.fr       */
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

double				compute_disorder(t_node *stack);

int					is_flag(char *s);
int					is_number(char *s);
int					has_duplicate(t_node *stack, int value);

void				sa(t_node *stack);
void				sb(t_node *stack);
void				ss(t_node *a, t_list *b);

void				pa(t_node *a, t_list *b);
void				pb(t_node *a, t_list *b);

void				ra(t_node *stack);
void				rb(t_node *stack);

void				rr(t_node *a, t_list *b);
void				rra(t_node *stack);
void				rrb(t_node *stack);
void				rrr(t_node *a, t_list *b);

#endif
