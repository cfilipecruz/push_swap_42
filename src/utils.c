/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:59:41 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/06 18:30:23 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf(2, "Error\n");
}

int	error_exit(t_node *stack_a, t_node *stack_b)
{
	print_error();
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}

int	clean_exit(t_node *stack_a, t_node *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

void	free_stack(t_node *stack)
{
	t_node	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
