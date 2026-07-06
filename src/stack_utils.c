/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:30:00 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/06 18:44:13 by joavieir         ###   ########.fr       */
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
	current = last_node(*node);
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

t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_sorted(t_node *stack)
{
	int		sorted;
	t_node	*cur;

	sorted = 1;
	cur = stack;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
		{
			sorted = 0;
			break ;
		}
		cur = cur->next;
	}
	return (sorted);
}
