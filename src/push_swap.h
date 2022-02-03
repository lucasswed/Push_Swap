/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:32:56 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/03 12:26:06 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

int		errors(int ac, char **av);
int		ft_issorted(t_list *stack_a);
int		ft_find_smaller(t_list *stack);

void	algo2(t_list **stack_a);
void	choose_case(t_list **stack_a);
void	swap(t_list **stack, int option);
void	rotate(t_list **stack, int option);
void	rr(t_list **stack_a, t_list **stack_b);
void	algo4(t_list **stack_a, t_list **stack_b);
void	algo5(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack, int option);
//void	algo100(t_list **stack_a, t_list **stack_b);
void	push(t_list **src, t_list **dest, int option);
void	reverse_rotate_all(t_list **stack_a, t_list stack_b);
void	ft_do_push(t_list **stack_a, t_list **stack_b, int counter, int o);

#endif