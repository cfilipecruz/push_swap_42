/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 00:55:41 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/04 00:35:01 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_node *b)
{
	t_node	*curr;
	int		max_val;
	int		max_pos;
	int		i;

	curr = b;
	max_val = b->value;
	max_pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->value > max_val)
		{
			max_val = curr->value;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

void	set_ranks(t_node *stack_a, int *temp_ranks)
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

int	*get_ranks(t_node *stack_a, int size)
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