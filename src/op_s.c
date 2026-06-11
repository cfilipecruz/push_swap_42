/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:48:10 by joavieir          #+#    #+#             */
/*   Updated: 2026/06/10 23:23:34 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	sa(t_node *stack_a)
{
	stack_swap(stack_a);
}

void	sb(t_node *stack_b)
{
	stack_swap(stack_b);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
