/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:57:47 by joavieir          #+#    #+#             */
/*   Updated: 2026/04/27 22:49:17 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;
	char	*ret;

	i = 0;
	size = 0;
	while (s1[i++])
		size++;
	i = 0;
	while (s2[i++])
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ret = str;
	while (*s1)
		*(str++) = *(s1++);
	while (*s2)
		*(str++) = *(s2++);
	*str = '\0';
	return (ret);
}
