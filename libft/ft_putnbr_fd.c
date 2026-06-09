/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:32:58 by joavieir          #+#    #+#             */
/*   Updated: 2026/05/18 17:42:34 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		digits;

	digits = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		digits++;
		write(fd, "-", 1);
	}
	if (num >= 10)
	{
		digits += ft_putnbr_fd(num / 10, fd);
		digits++;
		ft_putchar_fd((num % 10) + '0', fd);
	}
	else
	{
		digits++;
		ft_putchar_fd(num + '0', fd);
	}
	return (digits);
}
