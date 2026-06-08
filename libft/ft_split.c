/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:22:22 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:44:32 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static int	count_letters(char const *s, char c, int p)
{
	int	count;

	count = 0;
	while (s[p] && s[p] != c)
	{
		count++;
		p++;
	}
	return (count);
}

static char	*get_words(char const *s, int p, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i + p];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_memory(char **words, int j)
{
	while (j >= 0)
	{
		free(words[j]);
		j--;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nw;
	char	**words;
	int		len;
	int		j;

	nw = count_words(s, c);
	words = (char **)malloc((nw + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (nw > j)
	{
		while (s[i] && s[i] == c)
			i++;
		len = count_letters(s, c, i);
		words[j] = get_words(s, i, len);
		if (!words[j])
			return (free_memory(words, j - 1));
		i += len;
		j++;
	}
	words[j] = NULL;
	return (words);
}
