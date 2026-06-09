/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:45:07 by joavieir          #+#    #+#             */
/*   Updated: 2026/04/21 21:25:24 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sp1;
	const unsigned char	*sp2;
	size_t				i;

	i = 0;
	sp1 = (const unsigned char *) s1;
	sp2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (sp1[i] != sp2[i])
			return (sp1[i] - sp2[i]);
		i++;
	}
	return (0);
}
