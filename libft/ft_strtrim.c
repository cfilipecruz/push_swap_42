/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:50:12 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:45:06 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkchar(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && checkchar(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && checkchar(s1[end - 1], set))
		end--;
	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
