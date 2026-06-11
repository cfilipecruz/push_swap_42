/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/11 23:36:37 by cmarques         ###   ########.fr       */
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
			if (!is_valid_number(argument))
				return (error_exit(stack_a, stack_b));
			value = ft_atoi(argument);
			if (has_duplicate(stack_a, value) || !append_node(&stack_a, value))
				return (error_exit(stack_a, stack_b));
		}
		i++;
	}
	if(is_sorted(stack_a))
		return(0);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
