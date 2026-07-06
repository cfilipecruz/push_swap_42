/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 13:37:03 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/06 17:27:59 by joavieir         ###   ########.fr       */
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
	return (MODE_INVALID);
}

static int	run_algo(t_node **stack_a, t_node **stack_b,
		double disorder, t_options options)
{
	int	ret;

	if (options.bench == MODE_BENCH)
		benchmark_start(disorder, options.strat);
	if (is_sorted(*stack_a))
		return (1);
	if (stack_size(*stack_a) == 2)
		ret = ra(stack_a);
	else if (options.strat == STRATEGY_SIMPLE || stack_size(*stack_a) <= 5)
		ret = algo_simple(stack_a, stack_b);
	else if (options.strat == STRATEGY_MEDIUM)
		ret = algo_medium(stack_a, stack_b);
	else if (options.strat == STRATEGY_COMPLEX)
		ret = algo_complex(stack_a, stack_b);
	else
		ret = algo_adaptive(stack_a, stack_b, disorder);
	if (options.bench == MODE_BENCH)
		benchmark("benchend");
	return (ret);
}

static int	parse_args(int argc, char **argv, t_node **stack_a,
		t_options *options)
{
	int	i;
	int	flag;

	i = 0;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
		{
			flag = is_valid_flag(argv[i]);
			if (flag == MODE_BENCH)
				options->bench = MODE_BENCH;
			else if (flag == MODE_INVALID)
				return (0);
			else
			{
				if (options->strat != (t_strategy) MODE_INVALID)
					return (0);
				else
					options->strat = flag;
			}
		}
		else if (!handle_number(argv[i], stack_a))
			return (0);
	}
	return (1);
}

int	exec_stack(int argc, char **argv, t_node **stack_a, t_node **stack_b)
{
	t_options	options;

	options.bench = MODE_INVALID;
	options.strat = (t_strategy) MODE_INVALID;
	if (argc < 2)
		return (-1);
	if (!parse_args(argc, argv, stack_a, &options))
		return (0);
	if (options.strat == (t_strategy) MODE_INVALID)
		options.strat = STRATEGY_ADAPTIVE;
	if (options.bench == MODE_BENCH)
		benchmark("bench");
	else
		benchmark("!bench");
	return (run_algo(stack_a, stack_b,
			compute_disorder(*stack_a), options));
}
