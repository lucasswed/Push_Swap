/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:35:08 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/01/17 01:56:03 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

void	algo2(t_list **stack_a);
void	choose_case(t_list **stack_a);
void	swap(t_list **stack, int option);
void	rotate(t_list **stack, int option);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack, int option);
void	push(t_list **src, t_list **dest, int option);
void	algo5(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_all(t_list **stack_a, t_list stack_b);

int		errors(int ac, char **av);
int		ft_issorted(t_list *stack_a);

#endif