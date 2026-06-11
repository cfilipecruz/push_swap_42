/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:59:41 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/11 23:28:26 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(t_node *stack_a, t_node *stack_b)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
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
