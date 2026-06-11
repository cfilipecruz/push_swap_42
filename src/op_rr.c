/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:02:23 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/11 00:20:21 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_up(t_node **stack)
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
void	rra(t_node **stack_a)
{
	if (rotate_up(stack_a))
		write(1, "rra\n", 4);
}
void	rrb(t_node **stack_b)
{
	if (rotate_up(stack_b))
		write(1, "rrb\n", 4);
}
void	rrr(t_node **stack_a, t_node **stack_b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate_up(stack_a);
	rotated_b = rotate_up(stack_b);
	if (rotated_a || rotated_b)
		write(1, "rrr\n", 4);
}
