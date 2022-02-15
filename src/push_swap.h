/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:32:56 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/15 17:39:01 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

int		ft_cost_rr(t_list *spot);
int		errors(int ac, char **av);
int		ft_issorted(t_list *stack_a);
int		ft_find_smaller(t_list *stack);
int		ft_find_median(t_list **stack_a);
int		*ft_sort(t_list **stack_a, int ac);
int		ft_cost_r(t_list *stack_a, t_list *spot);

void	algo2(t_list **stack_a);
void	choose_case(t_list **stack_a);
void	swap(t_list **stack, int option);
void	rotate(t_list **stack, int option);
void	final_sort(t_list **stack_a, int ac);
void	rr(t_list **stack_a, t_list **stack_b);
void	algo5(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack, int option);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	push(t_list **src, t_list **dest, int option);
void	algo100(t_list **stack_a, t_list **stack_b, int ac);
void	reverse_rotate_all(t_list **stack_a, t_list stack_b);
void	ft_do_push(t_list **stack_a, t_list **stack_b, int counter, int o);

t_list	*last_great(t_list **stack_a);
t_list	*ft_smaller(t_list *stack_a);
t_list	*find_spot(t_list *stack_a, t_list *stack_b);

void	print_lst(t_list *lst);

#endif