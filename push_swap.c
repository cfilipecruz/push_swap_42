/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/09 17:48:14 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_int(int n)
{
	char	c;

	if (n >= 10)
		print_int(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static int	append_node(t_node **node, int value)
{
	t_node	*temp;
	t_node current;

	current = *node;
	temp = malloc(sizeof(t_node));
	if (!temp)
		return (0);
	temp->value = value;
	temp->next = NULL;
	if (*node == NULL){
		*node = temp;
		return (1);
	}
	while(current->next){
		current = current -> next;
	}
	current->next = temp;
	return (1);
}

static int	is_flag(char *s)
{
	if (s[0] == '-' && s[1] == '-')
		return (1);
	return (0);
}

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
	return ((double) mistakes / total_pairs);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->value, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_node *stack_a;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			//handle_flag(argv[i]);
			write(1, "\n", 1);
		}
		else
		{
			append_node(&stack_a, atoi(argv[i]));
		}
		i++;
	}
	print_stack(stack_a);
	return (0);
}
