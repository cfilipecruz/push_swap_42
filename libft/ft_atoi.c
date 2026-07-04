/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:07:05 by cmarques          #+#    #+#             */
/*   Updated: 2026/07/04 00:53:01 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	skip_whitespaces(char *atr)
{
	int	counter;

	counter = 0;
	while (atr[counter] == ' ' || atr[counter] == '\t' || atr[counter] == '\n'
		|| atr[counter] == '\v' || atr[counter] == '\f' || atr[counter] == '\r')
		counter++;
	return (counter);
}

int	ft_atoi(char *atr)
{
	int	counter;
	long	digit;
	int	sign;

	sign = 1;
	digit = 0;
	counter = skip_whitespaces(atr);
	if (atr[counter] == '-')
	{
		sign *= -1;
		counter++;
	}
	else if (atr[counter] == '+')
		counter++;
	while (atr[counter] >= '0' && atr[counter] <= '9')
	{
		digit = digit * 10 + (atr[counter] - '0');
		counter++;
	}
	return (digit * sign);
}
