/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:05:46 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/07 18:04:39 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		letter;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char *)s;
	letter = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == letter)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
