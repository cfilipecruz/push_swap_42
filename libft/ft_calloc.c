/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:30:45 by cmarques          #+#    #+#             */
/*   Updated: 2026/05/05 19:49:50 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new_string;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > ((size_t)-1) / nmemb)
		return (NULL);
	new_string = malloc(size * nmemb);
	if (!new_string)
		return (NULL);
	ft_bzero(new_string, size * nmemb);
	return (new_string);
}
