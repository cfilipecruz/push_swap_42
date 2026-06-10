/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/10 18:01:21 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*stack_a;
	char	*argument;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		argument = argv[i];
		if (!is_flag(argument))
		{
			if (is_valid_number(argument))
			{
				value = ft_atoi(argument);
				if (has_duplicate(stack_a, value))
				{
					write(2, "Error\n", 6);
					free_stack(stack_a);
					return (1);
				}
				if (!append_node(&stack_a, value))
				{
					free_stack(stack_a);
					return (1);
				}
			}
			else
			{
				write(2, "Error\n", 6);
				free_stack(stack_a);
				return (1);
			}
		}
		i++;
	}
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
