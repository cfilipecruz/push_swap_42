/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/09 21:06:25 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	append_node(t_node **node, int value)
{
	t_node	*temp;
	t_node *current;

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

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
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
	char *argument;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		*argument = argv[i];
		if (is_flag(argument))
		{
			//handle_flag(argv[i]);
			write(1, "\n", 1);
		}
		else
		{	if(is_number(argument)){
				append_node(&stack_a, ft_atoi(argument));
			}	
			else{
				write(2, "Error\n", 6);
				return(1);
			}
		}
		if (has_duplicate(stack_a, ft_atoi(argument)))
		{
			write(2, "Error\n", 6);
			return (1);
		}	
		i++;
	}

	print_stack(stack_a);
	return (0);
}
