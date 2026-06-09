/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:51 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/08 17:56:11 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*lstget_at(t_list *list, size_t index)
{
	while (list && index--)
		list = list->next;
	return (list);
}

double	compute_disorder(t_list *stack)
{
	t_list	*a;
	t_list	*b;
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
			if (*(int *) a->content > *(int *) b->content)
				mistakes++;
			b = b->next;
		}
		a = a->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double) mistakes / total_pairs);
}

int	*parse_args(int argc, char **argv, int *size)
{
	int	*ret;
	char	**nums;

	if (argc == 3)
		nums = ft_split(argv[2], ' ');
	else
		nums = argv;
	
	// TODO Add proper validation
	// TODO Finish function

}

int	main(int argc, char **argv)
{
	int	size;
	int	*nums;

	if (argc < 2)
		return (1);

	nums = parse_args(argc, argv, &size);

	// TODO A lot...

	return (0);
}
