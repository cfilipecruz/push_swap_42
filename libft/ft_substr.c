/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:33 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/07 18:36:54 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;
	size_t	lens;

	i = 0;
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup(""));
	if (len > lens - start)
		len = lens - start;
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (i < len)
	{
		new_string[i] = s[i + start];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
