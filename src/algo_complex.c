/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:50:24 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/04 01:28:59 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bit(int rank, int position)
{
	int	bit;

	rank = rank >> position;
	bit = rank & 1;

	return (bit);
}
static int	get_max_rank(int size)
{
	int	max_rank;
	int	i;

	max_rank = size - 1;
	i = 0;
	while (max_rank > 0)
	{
		max_rank = max_rank >> 1;
		i++;
	}
	return (i);
}

int	algo_complex(t_node **stack_a, t_node **stack_b)
{
	int	*temp_ranks;
	int	size;
	int	max_rank;
	int position;

	size = stack_size(*stack_a);
	temp_ranks = get_ranks(*stack_a, size);
	if (!temp_ranks)
		return (0);
	set_ranks(*stack_a, temp_ranks);
	free(temp_ranks);
	max_rank = get_max_rank(size);
	position = 0;
	while ()
	{
		while ()
		{
			if (get_bit(max_rank, position))
			{
				pa(stack_a, stack_b);
			}
			else
			{
				ra(stack_a);
			}
		}
		position++;
	}
	return (1);
}
