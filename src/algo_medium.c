/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:50:24 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/02 02:05:39 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunker_move_to_b(t_node **stack_a, t_node **stack_b)
{
	int	position;
	int	moves;
	int	size;

	while (*stack_b)
	{
		position = get_max_pos(*stack_b);
		size = stack_size(*stack_b);
		if (size / 2 <= position)
		{
			moves = size - position;
			while (moves > 0)
			{
				rrb(stack_b);
				moves--;
			}
		}
		else
		{
			while (position > 0)
			{
				rb(stack_b);
				position--;
			}
		}
		pa(stack_a, stack_b);
	}
}

static void	chunker_move_to_a(t_node **stack_a, t_node **stack_b,
		int chunk_size)
{
	int	sent_to_b;

	sent_to_b = 0;
	while (*stack_a)
	{
		if ((*stack_a)->value < (sent_to_b + chunk_size))
		{
			pb(stack_a, stack_b);
			sent_to_b++;
		}
		else
		{
			ra(stack_a);
		}
	}
}

static void	set_ranks(t_node *stack_a, int *temp_ranks)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->value = temp_ranks[i];
		stack_a = stack_a->next;
		i++;
	}
}

static int	*get_ranks(t_node *stack_a, int size)
{
	int		*temp_ranks;
	int		i;
	int		rank;
	t_node	*first;
	t_node	*current;

	i = 0;
	temp_ranks = malloc(size * sizeof(int));
	if (!temp_ranks)
		return (free(temp_ranks), NULL);
	current = stack_a;
	while (current)
	{
		rank = 0;
		first = stack_a;
		while (first)
		{
			if (first->value < current->value)
				rank++;
			first = first->next;
		}
		temp_ranks[i++] = rank;
		current = current->next;
	}
	return (temp_ranks);
}

int	algo_medium(t_node **stack_a, t_node **stack_b)
{
	int	chunk_size;
	int	*temp_ranks;
	int	size;

	size = stack_size(*stack_a);
	chunk_size = ft_sqrt(size);
	temp_ranks = get_ranks(*stack_a, size);
	if (!temp_ranks)
		return (0);
	set_ranks(*stack_a, temp_ranks);
	free(temp_ranks);
	chunker_move_to_a(stack_a, stack_b, chunk_size);
	chunker_move_to_b(stack_a, stack_b);
	return (1);
}
