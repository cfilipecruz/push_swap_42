/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:03:31 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/10 23:58:17 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	temp = *stack;
	while (current->next)
	{
		current = current->next;
	}
	*stack = (*stack)->next;
	current->next = temp;
	temp->next = NULL;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
}
void	rb(t_node **stack_b)
{
	rotate(stack_b);
}
void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
