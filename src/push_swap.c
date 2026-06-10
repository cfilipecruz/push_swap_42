/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/10 21:39:06 by cmarques         ###   ########.fr       */
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
	print_stacks("original", stack_a, stack_b);
	sa(stack_a);
	print_stacks("after sa", stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stacks("after pb", stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
