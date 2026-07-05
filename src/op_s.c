/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:48:10 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/05 02:01:11 by joavieir         ###   ########.fr       */
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

int	sa(t_node *stack_a)
{
	if (stack_swap(stack_a))
	{
		benchmark("sa");
		return (1);
	}
	return (0);
}

int	sb(t_node *stack_b)
{
	if (stack_swap(stack_b)){
		benchmark("sb");
		return (1);
	}
	return(0);
}

int	ss(t_node *stack_a, t_node *stack_b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = stack_swap(stack_a);
	swapped_b = stack_swap(stack_b);
	if (swapped_a || swapped_b){
		benchmark("ss");
		return(1);
	}
	return(0);
		
}
