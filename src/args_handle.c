/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:55:57 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/05 01:27:28 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *s)
{
	if (s[0] == '-' && s[1] == '-')
		return (1);
	return (0);
}

int	is_valid_number(char *s)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		number = (number * 10) + (s[i] - '0');
		if (sign == 1 && number > 2147483647)
			return (0);
		if (sign == -1 && number > 2147483648)
			return (0);
		i++;
	}
	return (1);
}
