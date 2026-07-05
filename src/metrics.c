/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:45:00 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/05 01:27:10 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node *stack)
{
	t_node	*a;
	t_node	*b;
	int		mistakes;
	int		total_pairs;

	a = stack;
	mistakes = 0;
	total_pairs = 0;
	while (a)
	{
		b = a->next;
		while (b)
		{
			total_pairs++;
			if (a->value > b->value)
				mistakes++;
			b = b->next;
		}
		a = a->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}
