/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:08:37 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:44:36 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*new_string;

	i = 0;
	j = 0;
	while (s[i])
	{
		i++;
	}
	new_string = malloc((i + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (s[j])
	{
		new_string[j] = s[j];
		j++;
	}
	new_string[j] = '\0';
	return (new_string);
}
