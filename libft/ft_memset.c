/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:03:50 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:44:18 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)p)[i] = (unsigned char)c;
		i += 1;
	}
	return (p);
}
