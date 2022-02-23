/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:04:49 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/23 10:42:50 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_all(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

void	ft_initialize_lst(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}
