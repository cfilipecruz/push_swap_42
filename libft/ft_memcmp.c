/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:05:42 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:44:10 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			i;
	const char	*string1;
	const char	*string2;

	i = 0;
	string1 = (const char *)s1;
	string2 = (const char *)s2;
	while (n != 0)
	{
		if (string1[i] != string2[i])
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
		n--;
	}
	return (0);
}
