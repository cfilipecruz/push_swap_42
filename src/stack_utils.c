/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:30:00 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/11 22:38:36 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	append_node(t_node **node, int value)
{
	t_node	*temp;
	t_node	*current;

	current = *node;
	temp = malloc(sizeof(t_node));
	if (!temp)
		return (0);
	temp->value = value;
	temp->next = NULL;
	if (*node == NULL)
	{
		*node = temp;
		return (1);
	}
	while (current->next)
		current = current->next;
	current->next = temp;
	return (1);
}

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
