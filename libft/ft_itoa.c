/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:00:23 by joavieir          #+#    #+#             */
/*   Updated: 2026/04/27 20:29:15 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int		ret;
	long	num;

	ret = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		ret++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	num = n;
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (num < 0)
		num *= -1;
	while (len >= 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
