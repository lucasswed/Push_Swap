/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:33:00 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/04 17:43:09 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_small(t_list **stack_a, int *lst, int index)
{
	int		smaller;
	t_list	*cursor;

	cursor = *stack_a;
	smaller = cursor->content;
	while (cursor)
	{
		if (cursor->content < smaller && cursor->content > lst[index - 1])
			smaller = cursor->content;
		cursor = cursor->next;
	}
	return (smaller);
}

int	*ft_sort(t_list **stack_a, int ac)
{
	t_list	*cursor;
	int		index;
	int		*temp;

	cursor = *stack_a;
	index = 0;
	temp = (int *)malloc(ac * sizeof(int));
	if (!temp)
		return (NULL);
	while (index < ac)
	{
		while (cursor->content != ft_small(stack_a, temp, index))
			cursor = cursor->next;
		temp[index] = cursor->content;
		cursor = *stack_a;
		index++;
	}
	return (temp);
}

int	ft_find_median(t_list **stack_a, int ac)
{
	int	index_median;
	int	median;
	int	*list;

	list = (int *)malloc(ac * sizeof(int));
	if (!list)
		return (0);
	index_median = (ac - 2) / 2;
	list = ft_sort(stack_a, ac);
	median = list[index_median];
	return (median);
}

void	back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cursor_a;
	t_list	*cursor_b;

	cursor_a = *stack_a;
	cursor_b = *stack_b;
	if (cursor_b->content < ft_lstlast(*stack_a)->content)
	{
		while (cursor_b->content > (*stack_a)->content)
			rotate(stack_a, 1);
		push(stack_b, stack_a, 2);
	}
	else
	{
		push(stack_b, stack_a, 2);
		rotate(stack_a, 1);
	}
}

void	algo100(t_list **stack_a, t_list **stack_b, int ac)
{
	int	median;

	median = ft_find_median(stack_a, ac);
	while (ft_lstsize(*stack_a) != 3)
	{
		if ((*stack_a)->content > median)
			push(stack_a, stack_b, 1);
		else
		{
			push(stack_a, stack_b, 1);
			rotate(stack_b, 2);
		}
	}
	choose_case(stack_a);
	while (*stack_b)
		back_to_a(stack_a, stack_b);
}
