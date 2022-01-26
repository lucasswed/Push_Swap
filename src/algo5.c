/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:11:00 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/01/21 20:30:46 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_list *stack_a)
{
	t_list	*cursor;

	cursor = stack_a;
	while (cursor->next)
	{
		if (cursor->content > cursor->next->content)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

static int	ft_find_smaller(t_list *stack)
{
	t_list	*cursor;
	t_list	*smaller;
	int		counter;

	cursor = stack;
	smaller = stack;
	counter = 0;
	while (cursor)
	{
		if (cursor->content < smaller->content)
			smaller = cursor;
		cursor = cursor->next;
	}
	cursor = stack;
	while (cursor != smaller)
	{
		counter++;
		cursor = cursor->next;
	}
	return (counter);
}

static void	ft_do_push(t_list **stack_a, t_list **stack_b, int counter, int o)
{
	if (counter > 2)
	{
		if (o == 1)
			counter = 5 - counter;
		else
			counter = 4 - counter;
		while (counter)
		{
			reverse_rotate(stack_a, 1);
			counter--;
		}
	}
	else
	{
		while (counter)
		{
			rotate(stack_a, 2);
			counter--;
		}
	}
	push(stack_a, stack_b, 1);
}

void	algo5(t_list **stack_a, t_list **stack_b)
{
	t_list	*cursor;
	int		counter;

	cursor = *stack_a;
	counter = ft_find_smaller(cursor);
	ft_do_push(stack_a, stack_b, counter, 1);
	cursor = *stack_a;
	counter = ft_find_smaller(cursor);
	ft_do_push(stack_a, stack_b, counter, 2);
	if (!(ft_issorted(*stack_a)))
		choose_case(stack_a);
	push(stack_b, stack_a, 2);
	push(stack_b, stack_a, 2);
}
