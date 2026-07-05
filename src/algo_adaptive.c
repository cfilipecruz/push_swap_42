/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:50:24 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/05 02:35:15 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo_adaptive(t_node **stack_a, t_node **stack_b, double disorder, int bench)
{
	if (disorder < 0.2)
		return (algo_simple(stack_a, stack_b, bench));
	if (disorder <= 0.5)
		return (algo_medium(stack_a, stack_b, bench));
	return (algo_complex(stack_a, stack_b, bench));
}
