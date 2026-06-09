/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:10:16 by cmarques          #+#    #+#             */
/*   Updated: 2026/06/08 17:55:24 by joavieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	**parse_args(int argc, char **argv, int *size);
double	compute_disorder(t_list *stack);

void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *a, t_list *b);
void	pa(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b);
void	ra(t_list *stack);
void	rb(t_list *stack);
void	rr(t_list *a, t_list *b);
void	rra(t_list *stack);
void	rrb(t_list *stack);
void	rrr(t_list *a, t_list *b);

#endif
