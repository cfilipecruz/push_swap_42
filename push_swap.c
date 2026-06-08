/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/08 16:18:37 by cmarques         ###   ########.fr       */
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

static t_node	*expand_stack(t_node *previous_node, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = previous_node;
	return (node);
}

static int	is_flag(char *s)
{
	if (s[0] == '-' && s[1] == '-')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*node;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			//handle_flag(argv[i]);
			write(1, "\n", 1);
		}
		else
		{
			node = ft_lstnew(atoi(argv[i]));
			expand_stack(&node, atoi(argv[i]));
		}
		i++;
	}
	return (0);
}
