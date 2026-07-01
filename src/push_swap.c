/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/17 18:54:29 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack(argc, argv, &stack_a, &stack_b, compute_disorder(stack_a)))
		return (error_exit(stack_a, stack_b));

	// printf("Input Stack:\n");
	// print_stack(stack_a);
	// printf("Disorder: %.2f\n", compute_disorder(stack_a));

	if (is_sorted(stack_a))
		return (clean_exit(stack_a, stack_b));
	return (clean_exit(stack_a, stack_b));
}
