/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:17:46 by joavieir          #+#    #+#             */
/*   Updated: 2026/04/29 18:01:01 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char c, char const *set)
{
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	while (s1[start] && ft_contains(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_contains(s1[end - 1], set))
		end--;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (NULL);
	while (start < end)
		ret[i++] = s1[start++];
	ret[i] = '\0';
	return (ret);
}
