/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:50:24 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/01 23:19:22 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int set_ranks(t_node *stack_a)
{
	(void)stack_a;
	return (1);
}

int	algo_medium(t_node **stack_a, t_node **stack_b)
{
	int size;
	int chunk_size;
	t_node *new_values;
	int i;

	size = stack_size(*stack_a);
	chunk_size = ft_sqrt(size);

	set_ranks(*stack_a);

	print_stack(*stack_a);

	while (stack_a)
	{
		i = 1;
		while (i <= chunk_size)
		{
			(*stack_a)->value;
			*stack_a = (*stack_a)->next;
			i++;
		}
		stack_b;
		return (1);
	}
}
