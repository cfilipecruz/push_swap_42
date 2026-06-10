/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:59:41 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/10 18:00:59 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->value, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

void	print_stacks(char *label, t_node *stack_a, t_node *stack_b)
{
	ft_putstr_fd("\n--- ", 1);
	ft_putstr_fd(label, 1);
	ft_putstr_fd(" ---\n", 1);
	ft_putstr_fd("stack a:\n", 1);
	print_stack(stack_a);
	ft_putstr_fd("stack b:\n", 1);
	print_stack(stack_b);
}
