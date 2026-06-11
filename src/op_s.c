/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:48:10 by joavieir          #+#    #+#             */
/*   Updated: 2026/06/11 00:19:07 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_swap(t_node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return (0);
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	return (1);
}

void	sa(t_node *stack_a)
{
	if (stack_swap(stack_a))
		write(1, "sa\n", 3);
}

void	sb(t_node *stack_b)
{
	if (stack_swap(stack_b))
		write(1, "sb\n", 3);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = stack_swap(stack_a);
	swapped_b = stack_swap(stack_b);
	if (swapped_a || swapped_b)
		write(1, "ss\n", 3);
}
