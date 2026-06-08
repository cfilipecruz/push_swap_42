/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:50:56 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 17:44:49 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
		{
			i = i + 1;
		}
		return (i);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	if (size != 0)
	{
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}
