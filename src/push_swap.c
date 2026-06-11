/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/11 00:01:16 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*stack_a;
	t_node	*stack_b;
	char	*argument;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
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
	write(2, "Before\n", 7);
	print_stack(stack_a);
	ra(&stack_a);
	ra(&stack_a);
	write(2, "After\n", 6);
	print_stack(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
