/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:55:47 by joavieir          #+#    #+#             */
/*   Updated: 2026/04/29 18:08:53 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freestrings(char **strings, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(strings[i++]);
	free(strings);
	return (NULL);
}

static char	**ft_copystring(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		arr[k] = malloc(sizeof(char) * (j - i + 1));
		if (!arr[k])
			return (ft_freestrings(arr, k));
		l = 0;
		while (i < j)
			arr[k][l++] = s[i++];
		arr[k++][l] = '\0';
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	strs;
	char	**ret;

	i = 0;
	strs = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
			|| (i != 0 && s[i] != c && s[i - 1] == c))
			strs++;
		i++;
	}
	ret = malloc(sizeof(char *) * (strs + 1));
	if (!ret)
		return (NULL);
	ret = ft_copystring(s, c, ret);
	if (!ret)
		return (NULL);
	ret[strs] = NULL;
	return (ret);
}
