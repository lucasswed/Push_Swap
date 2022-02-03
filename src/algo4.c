/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:14:32 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/03 14:13:55 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo4(t_list **stack_a, t_list **stack_b)
{
	t_list	*cursor;
	int		counter;

	cursor = *stack_a;
	counter = ft_find_smaller(cursor);
	ft_do_push(stack_a, stack_b, counter, 2);
	if (!(ft_issorted(*stack_a)))
		choose_case(stack_a);
	push(stack_b, stack_a, 2);
}