/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 01:48:23 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/06 19:05:48 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_moves(int *moves)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
		total += moves[i++];
	return (total);
}

static void	append_move_to_list(int *moves, const char *move)
{
	if (ft_strncmp(move, "sa", 3) == 0)
		moves[0]++;
	else if (ft_strncmp(move, "sb", 3) == 0)
		moves[1]++;
	else if (ft_strncmp(move, "ss", 3) == 0)
		moves[2]++;
	else if (ft_strncmp(move, "pa", 3) == 0)
		moves[3]++;
	else if (ft_strncmp(move, "pb", 3) == 0)
		moves[4]++;
	else if (ft_strncmp(move, "ra", 3) == 0)
		moves[5]++;
	else if (ft_strncmp(move, "rb", 3) == 0)
		moves[6]++;
	else if (ft_strncmp(move, "rr", 3) == 0)
		moves[7]++;
	else if (ft_strncmp(move, "rra", 4) == 0)
		moves[8]++;
	else if (ft_strncmp(move, "rrb", 4) == 0)
		moves[9]++;
	else if (ft_strncmp(move, "rrr", 4) == 0)
		moves[10]++;
}

static void	benchmark_end(int *moves, int is_on)
{
	if (is_on != 1)
		return ;
	ft_printf(2, "[bench] total_ops: %d\n", total_moves(moves));
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		moves[0], moves[1], moves[2], moves[3], moves[4]);
	ft_printf(2,
		"[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		moves[5], moves[6], moves[7], moves[8], moves[9], moves[10]);
}

void	benchmark_start(double disorder, t_strategy strat)
{
	char	*strat_string;

	if (strat == STRATEGY_SIMPLE)
		strat_string = ft_strdup("Simple / O(n2)");
	else if (strat == STRATEGY_MEDIUM)
		strat_string = ft_strdup("Medium / O(n√n)");
	else if (strat == STRATEGY_COMPLEX)
		strat_string = ft_strdup("Complex / O(n log n)");
	else if (strat == STRATEGY_ADAPTIVE)
	{
		if (disorder < 0.2)
			strat_string = ft_strdup("Adaptive / O(n2)");
		else if (disorder < 0.5)
			strat_string = ft_strdup("Adaptive / O(n√n)");
		else
			strat_string = ft_strdup("Adaptive / O(n log n)");
	}
	else
		strat_string = ft_strdup("\n[error] Something went VERY WRONG");
	ft_printf(2, "[bench] disorder: %d.%d%%\n", (int) (disorder * 100), (int) (disorder * 10000) % 100);
	ft_printf(2, "[bench] strategy: %s\n", strat_string);
}
void	benchmark(const char *move)
{
	static int	is_on;
	static int	moves[11];

	if (ft_strncmp(move, "bench", 6) == 0)
		is_on = 1;
	else if (ft_strncmp(move, "!bench", 7) == 0)
		is_on = 0;
	else if (ft_strncmp(move, "benchend", 9) == 0)
		benchmark_end(moves, is_on);
	else
	{
		ft_printf(1, "%s\n", move);
		append_move_to_list(moves, move);
	}
}
