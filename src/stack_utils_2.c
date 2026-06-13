/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 23:31:20 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/13 10:46:02 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_flag(int flag_number)
{
	if (flag_number == 5)
	{
		call_bench();
	}
}

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
		return (1);
	if (ft_strncmp(argument, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(argument, "--complex", 10) == 0)
		return (3);
	if (ft_strncmp(argument, "--adaptive", 11) == 0)
		return (4);
	if (ft_strncmp(argument, "--bench", 8) == 0)
		return (5);
	return (0);
}

int	init_stack(int argc, char **argv, t_node **stack_a)
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
			if (!flag)
				return (0);
			if (flag == 5)
				bench = 1;
		}
		else
		{
			if (!handle_number(argv[i], stack_a))
				return (0);
		}
		i++;
	}
	return (1);
}
