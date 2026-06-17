/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:22:15 by joavieir          #+#    #+#             */
/*   Updated: 2026/06/17 18:45:09 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	disordered(t_node *a, t_node *b)
{
	if (a->value < b->value)
		return (1);
	return (0);
}

// We loosely implement a bubble sort here.
int	algo_simple(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		length;
	int		sorted;
	int		min;

	(void) stack_b;
	length = stack_size(*stack_a);
	sorted = 0;
	min = min_value(*stack_a);
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i++ < length - 1)
		{
			if (disordered(*stack_a, (*stack_a)->next))
			{
				sa(*stack_a);
				sorted = 0;	
			}
			ra(stack_a);
		}
		ra(stack_a);
	}
	while ((*stack_a)->value != min)
		ra(stack_a);
	return (sorted);
}
