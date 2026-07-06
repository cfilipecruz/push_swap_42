/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:07:19 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/06 20:16:43 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pull_back_to_a(t_node **a, t_node **b)
{
	int	target_pos;
	int	size_a;

	target_pos = get_target_a_pos((*b)->value, *a);
	size_a = stack_size(*a);
	if (target_pos <= size_a / 2)
	{
		while (target_pos-- > 0)
			ra(a);
	}
	else
	{
		while (target_pos++ < size_a)
			rra(a);
	}
	pa(a, b);
}

void	push_cheapest_to_b(t_node **a, t_node **b)
{
	t_node	*curr;
	int		info[4];
	int		path;

	info[0] = get_cheapest_a_pos(*a, *b);
	curr = *a;
	info[1] = 0;
	while (info[1] < info[0])
	{
		curr = curr->next;
		info[1]++;
	}
	info[1] = get_target_b_pos(curr->value, *b);
	info[2] = stack_size(*a);
	info[3] = stack_size(*b);
	get_best_path(info, &path);
	execute_moves(a, b, info[0], info[1]);
}

void	sort_three(t_node **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;
	if (f > s && s < t && f < t)
		sa(*a);
	else if (f > s && s > t)
	{
		sa(*a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(*a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}

int	algo_simple(t_node **stack_a, t_node **stack_b)
{
	int	min_pos;
	int	size_a;

	if (stack_size(*stack_a) == 2)
		return (ra(stack_a));
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 3)
		push_cheapest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pull_back_to_a(stack_a, stack_b);
	min_pos = get_min_pos(*stack_a);
	size_a = stack_size(*stack_a);
	if (min_pos <= size_a / 2)
		while (min_pos-- > 0)
			ra(stack_a);
	else
		while (min_pos++ < size_a)
			rra(stack_a);
	return (1);
}
