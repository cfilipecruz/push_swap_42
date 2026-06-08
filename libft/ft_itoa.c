/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:21:47 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 18:22:01 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*write_string(long int n, int len, int s)
{
	char	*new_string;
	int		i;

	i = len;
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	new_string[len] = '\0';
	if (s == 1)
		new_string[0] = '-';
	while (i > s)
	{
		i--;
		new_string[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (new_string);
}

char	*ft_itoa(int n)
{
	char		*new_string;
	int			s;
	int			len;
	long int	np;

	s = 0;
	np = n;
	if (n < 0)
	{
		s = 1;
		np = -np;
	}
	len = count_numbers(np) + s;
	new_string = write_string(np, len, s);
	if (!new_string)
		return (NULL);
	return (new_string);
}
