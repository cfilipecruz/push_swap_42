/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:09:22 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/06 18:32:46 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conv(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	puthex(unsigned long num, int upper, int fd)
{
	int			digits;
	const char	hex[] = "0123456789abcdef";

	digits = 0;
	if (num >= 16)
		digits += puthex(num / 16, upper, fd);
	if (upper)
		digits += ft_putchar_fd(ft_toupper(hex[num % 16]), fd);
	else
		digits += ft_putchar_fd(hex[num % 16], fd);
	return (digits);
}

static int	putptr(void *ptr, int fd)
{
	unsigned long	num;

	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	num = (unsigned long) ptr;
	ft_putstr_fd("0x", fd);
	return (2 + puthex(num, 0, fd));
}

static int	handle_conv(int fd, int c, va_list *list)
{
	char	*str;

	if (c == 'c')
		return (ft_putchar_fd((char) va_arg(*list, int), 1));
	else if (c == 's')
	{
		str = va_arg(*list, char *);
		if (!str)
			return (ft_putstr_fd("(null)", fd));
		return (ft_putstr_fd(str, fd));
	}
	else if (c == 'p')
		return (putptr(va_arg(*list, void *), fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*list, int), fd));
	else if (c == 'u')
		return (ft_putunbr_fd(va_arg(*list, unsigned int), fd));
	else if (c == 'x')
		return (puthex(va_arg(*list, unsigned int), 0, fd));
	else if (c == 'X')
		return (puthex(va_arg(*list, unsigned int), 1, fd));
	else if (c == '%')
		return (ft_putchar_fd('%', fd));
	return (-1);
}

int	ft_printf(int fd, const char *fmt, ...)
{
	int		i;
	int		len;
	va_list	list;

	i = 0;
	len = 0;
	va_start(list, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] && is_conv(fmt[i + 1]))
		{
			len += handle_conv(fd, fmt[i + 1], &list);
			i += 2;
		}
		else
			len += ft_putchar_fd(fmt[i++], fd);
	}
	va_end(list);
	return (len);
}
