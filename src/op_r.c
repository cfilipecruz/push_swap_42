/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:03:31 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/05 01:59:48 by joavieir         ###   ########.fr       */
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

int	ra(t_node **stack_a)
{
	int	ret;

	ret = rotate_stack(stack_a);
	if (ret)
		benchmark("ra");
	return (ret);
}

int	rb(t_node **stack_b)
{
	int	ret;

	ret = rotate_stack(stack_b);
	if (ret)
		benchmark("rb");
	return (ret);
}

int	rr(t_node **stack_a, t_node **stack_b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate_stack(stack_a);
	rotated_b = rotate_stack(stack_b);
	if (rotated_a || rotated_b)
		benchmark("rr");
	return (rotated_a || rotated_b);
}
