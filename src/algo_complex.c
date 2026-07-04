/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:50:24 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/04 02:01:59 by cmarques         ###   ########.fr       */
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
static int	get_rank_bits(int size)
{
	int	max_rank;
	int	bits;

	max_rank = size - 1;
	bits = 0;
	while (max_rank > 0)
	{
		max_rank = max_rank >> 1;
		bits++;
	}
	return (bits);
}

int	algo_complex(t_node **stack_a, t_node **stack_b)
{
	int	*temp_ranks;
	int	size;
	int	bits;
	int	position;

	size = stack_size(*stack_a);
	temp_ranks = get_ranks(*stack_a, size);
	if (!temp_ranks)
		return (0);
	set_ranks(*stack_a, temp_ranks);
	free(temp_ranks);
	bits = get_rank_bits(size);
	position = 0;
	while (position < bits)
	{
		size = stack_size(*stack_a);
		while (size)
		{
			if (get_bit((*stack_a)->value, position))
			{
				ra(stack_a);
			}
			else
			{
				pb(stack_a, stack_b);
			}
			size--;
		}
		while(*stack_b){
			pa(stack_a, stack_b);
		}
		position++;
	}
	return (1);
}
