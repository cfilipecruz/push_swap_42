/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:02:23 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/05 01:26:53 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack_reverse(t_node **stack)
{
	t_node	*current;
	t_node	*previous;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	current = *stack;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = *stack;
	*stack = current;
	return (1);
}

int	rra(t_node **stack_a)
{
	int	ret;

	ret = rotate_stack_reverse(stack_a);
	if (ret)
		write(1, "rra\n", 4);
	return (ret);
}

int	rrb(t_node **stack_b)
{
	int	ret;

	ret = rotate_stack_reverse(stack_b);
	if (ret)
		write(1, "rrb\n", 4);
	return (ret);
}

int	rrr(t_node **stack_a, t_node **stack_b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate_stack_reverse(stack_a);
	rotated_b = rotate_stack_reverse(stack_b);
	if (rotated_a || rotated_b)
		write(1, "rrr\n", 4);
	return (rotated_a || rotated_b);
}
