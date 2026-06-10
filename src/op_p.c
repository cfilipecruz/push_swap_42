/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:50:26 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/10 21:32:38 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
    push_node(stack_b, stack_a);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
    push_node(stack_a, stack_b);
}
