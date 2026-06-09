/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:26:02 by joavieir          #+#    #+#             */
/*   Updated: 2026/04/21 19:15:00 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;
	unsigned int		i;

	if (n == 0 || (dest == src))
		return (dest);
	i = 0;
	dp = (unsigned char *) dest;
	sp = (const unsigned char *) src;
	while (dp > sp && n > 0)
	{
		n--;
		*(dp + n) = *(sp + n);
	}
	while (dp < sp && i < n)
	{
		*(dp + i) = *(sp + i);
		i++;
	}
	return (dp);
}
