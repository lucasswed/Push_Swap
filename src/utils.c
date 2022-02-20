/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:31:59 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/20 01:02:49 by lucas-ma         ###   ########.fr       */
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

// void	push_to_b(t_list **stack_a, t_list **stack_b)
// {
// 	float		median;
// 	int			counter;
// 	int			size;

// 	median = ft_find_quarter(stack_a);
// 	size = ft_lstsize(*stack_a);
// 	counter = 0;
// 	if ((*stack_a)->content < median)
// 		push(stack_a, stack_b, 1);
// 	else
// 		rotate(stack_a, 1);
// }

int	exist_chunk(t_list **stack_a, t_chunk ch)
{
	t_list	*cursor;

	cursor = *stack_a;
	while (cursor)
	{
		if (cursor->content >= ch.min_ch && cursor->content <= ch.max_ch)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

void	increment_chunk(t_chunk *chunk, int *list, int len)
{
	chunk->i_min += len;
	chunk->i_max = chunk->i_min + len;
	chunk->min_ch = list[chunk->i_min];
	chunk->max_ch = list[chunk->i_max];
}

void	push_chunk(t_list **stack_a, t_list **stack_b, t_chunk ch)
{
	if (*stack_a)
	{
		if ((*stack_a)->content >= ch.min_ch
			&& (*stack_a)->content <= ch.max_ch)
			push(stack_a, stack_b, 1);
		else
			rotate(stack_a, 1);
	}
}
t_list	*look_the_best(t_list **stack_a, t_list **stack_b)
{
	t_list	*c;
	t_list	*sp_c;
	t_list	*b;
	t_list	*sp_b;

	c = *stack_b;
	b = *stack_b;
	sp_b = find_spot(*stack_a, b);
	while (c)
	{
		sp_c = find_spot(*stack_a, c);
		if (calculate_steps(stack_a, stack_b, sp_c, c) < calculate_steps(stack_a, stack_b, sp_b, b))
		{
			b = c;
			sp_b = sp_c;
		}
		c = c->next;
	}
	return (b);
}