/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:28:37 by joavieir          #+#    #+#             */
/*   Updated: 2026/04/21 21:17:20 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			last = (char *) &s[i];
		i++;
	}
	if (s[i] == (unsigned char) c)
		last = (char *) &s[i];
	return (last);
}
