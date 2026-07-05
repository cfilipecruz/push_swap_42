/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:01:57 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/05 03:32:53 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_number(char *argument, t_node **stack_a)
{
	int	value;

	if (!is_valid_number(argument))
		return (0);
	value = ft_atoi(argument);
	if (has_duplicate(*stack_a, value))
		return (0);
	if (!append_node(stack_a, value))
		return (0);
	return (1);
}

static int	is_valid_flag(char *argument)
{
	if (ft_strncmp(argument, "--simple", 9) == 0)
		return (STRATEGY_SIMPLE);
	if (ft_strncmp(argument, "--medium", 9) == 0)
		return (STRATEGY_MEDIUM);
	if (ft_strncmp(argument, "--complex", 10) == 0)
		return (STRATEGY_COMPLEX);
	if (ft_strncmp(argument, "--adaptive", 11) == 0)
		return (STRATEGY_ADAPTIVE);
	if (ft_strncmp(argument, "--bench", 8) == 0)
		return (MODE_BENCH);
	return (0);
}

static int	run_algo(int flag, t_node **stack_a, t_node **stack_b,
		double disorder, int bench)
{
	int	ret;

	if (bench)
		benchmark_start(disorder, flag);
	if (stack_size(*stack_a) == 2)
		ret = ra(stack_a);
	else if (flag == STRATEGY_SIMPLE || stack_size(*stack_a) <= 5)
		ret = algo_simple(stack_a, stack_b, bench);
	else if (flag == STRATEGY_MEDIUM)
		ret = algo_medium(stack_a, stack_b, bench);
	else if (flag == STRATEGY_COMPLEX)
		ret = algo_complex(stack_a, stack_b, bench);
	else
		ret = algo_adaptive(stack_a, stack_b, disorder, bench);

	if (bench)
		benchmark("benchend");
	return (ret);
}

int	exec_stack(int argc, char **argv, t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		bench;
	int		mode;
	int		flag;

	i = 1;
	bench = MODE_INVALID;
	mode = MODE_INVALID;
	flag = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			flag = is_valid_flag(argv[i]);
			if (flag == MODE_BENCH)
				bench = MODE_BENCH;
			else
			{
				if (mode != MODE_INVALID)
					return (-1); // TODO throw proper error here (printing "Error" etc.)
				else
					mode = flag;
			}
		}
		else if (!handle_number(argv[i], stack_a))
			return (0);
		i++;
	}
	if (mode == MODE_INVALID)
		mode = STRATEGY_ADAPTIVE;
	if (bench == MODE_BENCH)
		benchmark("bench");
	else
		benchmark("!bench");
	return (run_algo(mode, stack_a, stack_b, compute_disorder(*stack_a), bench));
}
