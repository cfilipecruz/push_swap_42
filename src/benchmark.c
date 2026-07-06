/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 01:48:23 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/06 15:01:14 by joavieir         ###   ########.fr       */
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
	if (ft_strncmp(move, "sa", 2))
		moves[0]++;
	else if (ft_strncmp(move, "sb", 2))
		moves[1]++;
	else if (ft_strncmp(move, "ss", 2))
		moves[2]++;
	else if (ft_strncmp(move, "pa", 2))
		moves[3]++;
	else if (ft_strncmp(move, "pb", 2))
		moves[4]++;
	else if (ft_strncmp(move, "ra", 2))
		moves[5]++;
	else if (ft_strncmp(move, "rb", 2))
		moves[6]++;
	else if (ft_strncmp(move, "rr", 2))
		moves[7]++;
	else if (ft_strncmp(move, "rra", 2))
		moves[8]++;
	else if (ft_strncmp(move, "rrb", 2))
		moves[9]++;
	else if (ft_strncmp(move, "rrr", 2))
		moves[10]++;
}

static void	benchmark_end(int *moves, int is_on)
{
	if (is_on != 1)
		return ;
	fprintf(stderr, "[bench] total_ops: %d\n", total_moves(moves));
	fprintf(stderr, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		moves[0], moves[1], moves[2], moves[3], moves[4]);
	fprintf(stderr,
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
	fprintf(stderr, "[bench] disorder: %.2f\n", disorder);
	fprintf(stderr, "[bench] strategy: %s\n", strat_string);
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
		printf("%s\n", move);
		append_move_to_list(moves, move);
	}
}
