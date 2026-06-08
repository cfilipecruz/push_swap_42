/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:59:30 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 18:04:15 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		del(temp->content);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
