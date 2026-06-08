/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:13:04 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:44:42 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	buffer;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buffer = len1 + len2 + 1;
	result = malloc((buffer) * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, buffer);
	ft_strlcat(result, s2, buffer);
	return (result);
}
