/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joavieir <joavieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:51:01 by joavieir          #+#    #+#             */
/*   Updated: 2026/07/06 18:28:13 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	digits;

	digits = 0;
	if (n >= 10)
		digits += ft_putunbr_fd(n / 10, fd);
	digits += ft_putchar_fd((n % 10) + '0', fd);
	return (digits);
}
