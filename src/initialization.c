/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:01:57 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/05 02:05:08 by cmarques         ###   ########.fr       */
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

static int	run_algo(int flag, t_node **stack_a, t_node **stack_b,
		double disorder)
{
	if (stack_size(*stack_a) == 2)
		return (ra(stack_a));
	if (flag == STRATEGY_SIMPLE || stack_size(*stack_a) <= 5)
		return (algo_simple(stack_a, stack_b));
	else if (flag == STRATEGY_MEDIUM)
		return (algo_medium(stack_a, stack_b));
	else if (flag == STRATEGY_COMPLEX)
		return (algo_complex(stack_a, stack_b));
	else
		return (algo_adaptive(stack_a, stack_b, disorder));
}

int	init_stack(int argc, char **argv, t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		bench;
	int		flag;
	double	disorder;

	i = 1;
	bench = 0;
	flag = STRATEGY_ADAPTIVE;
	(void)bench;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			flag = is_valid_flag(argv[i]);
			if (flag == MODE_BENCH)
				bench = MODE_BENCH;
		}
		else if (!handle_number(argv[i], stack_a))
			return (0);
		i++;
	}
	disorder = compute_disorder(*stack_a);
	if (disorder == 0)
		return (1);
	return (run_algo(flag, stack_a, stack_b, disorder));
}
