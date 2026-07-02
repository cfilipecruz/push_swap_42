/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 00:55:41 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/02 00:58:08 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_node *b)
{
	t_node	*curr;
	int		max_val;
	int		max_pos;
	int		i;

	curr = b;
	max_val = b->value;
	max_pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->value > max_val)
		{
			max_val = curr->value;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}