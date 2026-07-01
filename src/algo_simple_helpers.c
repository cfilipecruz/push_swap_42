/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:00:00 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/01 17:26:13 by joavieir         ###   ########.fr       */
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

int	get_target_b_pos(int val, t_node *b)
{
	t_node	*curr;
	int		target_val;
	int		target_pos;
	int		i;

	curr = b;
	target_pos = -1;
	i = 0;
	while (curr)
	{
		if (curr->value < val && (target_pos == -1
				|| curr->value > target_val))
		{
			target_val = curr->value;
			target_pos = i;
		}
		curr = curr->next;
		i++;
	}
	if (target_pos == -1)
		return (get_max_pos(b));
	return (target_pos);
}

int	get_min_pos(t_node *a)
{
	t_node	*curr;
	int		min_val;
	int		min_pos;
	int		i;

	curr = a;
	min_val = a->value;
	min_pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_pos);
}

int	get_target_a_pos(int val, t_node *a)
{
	t_node	*curr;
	int		target_val;
	int		target_pos;
	int		i;

	curr = a;
	target_pos = -1;
	i = 0;
	while (curr)
	{
		if (curr->value > val && (target_pos == -1
				|| curr->value < target_val))
		{
			target_val = curr->value;
			target_pos = i;
		}
		curr = curr->next;
		i++;
	}
	if (target_pos == -1)
		return (get_min_pos(a));
	return (target_pos);
}

int	get_cheapest_a_pos(t_node *a, t_node *b)
{
	t_node	*curr;
	int		info[4];
	int		min_cost;
	int		best_pos;
	int		path;

	curr = a;
	info[0] = 0;
	info[2] = stack_size(a);
	info[3] = stack_size(b);
	min_cost = -1;
	best_pos = 0;
	while (curr)
	{
		info[1] = get_target_b_pos(curr->value, b);
		if (min_cost == -1 || get_best_path(info, &path) < min_cost)
		{
			min_cost = get_best_path(info, &path);
			best_pos = info[0];
		}
		curr = curr->next;
		info[0]++;
	}
	return (best_pos);
}