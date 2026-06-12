/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:03:31 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/12 23:18:13 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	current = *stack;
	temp = *stack;
	current = last_node(*stack);
	*stack = (*stack)->next;
	current->next = temp;
	temp->next = NULL;
	return (1);
}

void	ra(t_node **stack_a)
{
	if (rotate_stack(stack_a))
		write(1, "ra\n", 3);
}
void	rb(t_node **stack_b)
{
	if (rotate_stack(stack_b))
		write(1, "rb\n", 3);
}
void	rr(t_node **stack_a, t_node **stack_b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate_stack(stack_a);
	rotated_b = rotate_stack(stack_b);
	if (rotated_a || rotated_b)
		write(1, "rr\n", 3);
}
