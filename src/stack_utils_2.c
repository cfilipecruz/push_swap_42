/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 23:31:20 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/17 17:58:21 by joavieir         ###   ########.fr       */
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

static int	run_algo(int flag, t_node **stack_a, t_node **stack_b, double disorder)
{
	if (flag == STRATEGY_SIMPLE)
		return (algo_simple(stack_a, stack_b));
	else if (flag == STRATEGY_MEDIUM)
		return (algo_medium(stack_a, stack_b));
	else if (flag == STRATEGY_COMPLEX)
		return (algo_complex(stack_a, stack_b));
	else
		return (choose_algo(stack_a, stack_b, disorder));
}

int	init_stack(int argc, char **argv, t_node **stack_a, t_node **stack_b, double disorder)
{
	int	i;
	int	bench;
	int	flag;

	i = 1;
	bench = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			flag = is_valid_flag(argv[i]);
			if (flag == MODE_BENCH)
				bench = MODE_BENCH;
		}
		else
			if (!handle_number(argv[i], stack_a))
				return (0);
		i++;
	}
	return (run_algo(flag, stack_a, stack_b, disorder));
}
