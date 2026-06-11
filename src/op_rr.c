/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:02:23 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/11 00:13:54 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_node **stack)
{
	t_node	*current;
    t_node *previous;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	current = *stack;
	while (current->next)
	{
        previous = current;
		current = current->next;
	}
    previous->next = NULL;
	current->next = *stack;
	*stack = current;
}
void	rra(t_node **stack_a)
{
	rotate_up(stack_a);
}
void	rrb(t_node **stack_b)
{
	rotate_up(stack_b);
}
void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
