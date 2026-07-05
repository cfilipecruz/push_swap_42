/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:02:23 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/05 03:37:37 by joavieir         ###   ########.fr       */
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
		benchmark("rra");
	return (ret);
}

int	rrb(t_node **stack_b)
{
	int	ret;

	ret = rotate_stack_reverse(stack_b);
	if (ret)
		benchmark("rrb");
	return (ret);
}

int	rrr(t_node **stack_a, t_node **stack_b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate_stack_reverse(stack_a);
	rotated_b = rotate_stack_reverse(stack_b);
	if (rotated_a || rotated_b)
		benchmark("rrr");
	return (rotated_a || rotated_b);
}
