/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 22:11:22 by joavieir          #+#    #+#             */
/*   Updated: 2026/04/29 17:48:24 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nodes;
	t_list	*node;

	if (!lst)
		return (0);
	nodes = 1;
	node = lst->next;
	while (node)
	{
		node = node->next;
		nodes++;
	}
	return (nodes);
}
