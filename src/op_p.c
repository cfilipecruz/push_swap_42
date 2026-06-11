/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:50:26 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/11 00:24:24 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_node(t_node **stack_1, t_node **stack_2)
{
	t_node	*temp;

	if (!*stack_1)
		return (0);
	temp = *stack_1;
	*stack_1 = (*stack_1)->next;
	temp->next = *stack_2;
	*stack_2 = temp;
	return (1);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (push_node(stack_b, stack_a))
		write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (push_node(stack_a, stack_b))
		write(1, "pb\n", 3);
}
