/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:31:59 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/15 17:53:01 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_smaller(t_list *stack_a)
{
	t_list	*cursor;
	t_list	*smaller;

	cursor = stack_a;
	smaller = cursor;
	while (cursor)
	{
		if (cursor->content < smaller->content)
			smaller = cursor;
		cursor = cursor->next;
	}
	return (smaller);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int		median;

	median = ft_find_median(stack_a);
	if ((*stack_a)->content < median)
		push(stack_a, stack_b, 1);
	else
		rotate(stack_a, 1);
	if (ft_lstsize(*stack_a) > 3)
		push_to_b(stack_a, stack_b);
}

int	look_the_better(t_list **stack_a, t_list **stack_b)
{
	if (ft)
}