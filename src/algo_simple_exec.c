/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:07:05 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/01 17:25:40 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_best_path(int *info, int *path)
{
	int	costs[4];
	int	min_cost;
	int	i;

	costs[0] = max(info[0], info[1]);
	costs[1] = max(info[2] - info[0], info[3] - info[1]);
	costs[2] = info[0] + (info[3] - info[1]);
	costs[3] = (info[2] - info[0]) + info[1];
	min_cost = costs[0];
	*path = 1;
	i = 1;
	while (i < 4)
	{
		if (costs[i] < min_cost)
		{
			min_cost = costs[i];
			*path = i + 1;
		}
		i++;
	}
	return (min_cost);
}

void	exec_up(t_node **a, t_node **b, int p_a, int p_b)
{
	while (p_a > 0 && p_b > 0)
	{
		rr(a, b);
		p_a--;
		p_b--;
	}
	while (p_a-- > 0)
		ra(a);
	while (p_b-- > 0)
		rb(b);
}

void	exec_down(t_node **a, t_node **b, int p_a, int p_b)
{
	int	r_a;
	int	r_b;

	r_a = stack_size(*a) - p_a;
	r_b = stack_size(*b) - p_b;
	while (r_a > 0 && r_b > 0)
	{
		rrr(a, b);
		r_a--;
		r_b--;
	}
	while (r_a-- > 0)
		rra(a);
	while (r_b-- > 0)
		rrb(b);
}

void	execute_moves(t_node **a, t_node **b, int p_a, int p_b)
{
	int	path;
	int	info[4];

	info[0] = p_a;
	info[1] = p_b;
	info[2] = stack_size(*a);
	info[3] = stack_size(*b);
	get_best_path(info, &path);
	if (path == 1)
		exec_up(a, b, p_a, p_b);
	if (path == 2)
		exec_down(a, b, p_a, p_b);
	if (path == 3)
		while (p_a-- > 0)
			ra(a);
	if (path == 3)
		while (p_b++ < info[3])
			rrb(b);
	if (path == 4)
		while (p_a++ < info[2])
			rra(a);
	if (path == 4)
		while (p_b-- > 0)
			rb(b);
	pb(a, b);
}