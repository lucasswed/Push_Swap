/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:33:00 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/15 17:52:11 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_small(t_list **stack_a, int *lst, int index)
// {
// 	int		smaller;
// 	t_list	*cursor;

// 	cursor = *stack_a;
// 	smaller = cursor->content;
// 	while (cursor)
// 	{
// 		if (cursor->content < smaller && cursor->content > lst[index - 1])
// 			smaller = cursor->content;
// 		cursor = cursor->next;
// 	}
// 	return (smaller);
// }

// int	*ft_sort(t_list **stack_a, int ac)
// {
// 	t_list	*cursor;
// 	int		index;
// 	int		*temp;

// 	cursor = *stack_a;
// 	index = 0;
// 	temp = (int *)malloc(ac * sizeof(int));
// 	if (!temp)
// 		return (NULL);
// 	while (index < ac)
// 	{
// 		while (cursor->content != ft_small(stack_a, temp, index))
// 			cursor = cursor->next;
// 		temp[index] = cursor->content;
// 		cursor = *stack_a;
// 		index++;
// 	}
// 	return (temp);
// }

// int	ft_find_median(t_list **stack_a, int size)
// {
// 	// int	index_median;
// 	// int	median;
// 	// int	*list;

// 	// list = (int *)malloc(size * sizeof(int));
// 	// if (!list)
// 	// 	return (0);
// 	// index_median = size / 2;
// 	// list = ft_sort(stack_a, size);
// 	// median = list[index_median];
// 	// free(list);
// 	// return (median);
// }

int	ft_find_median(t_list **stack_a)
{
	t_list	*cursor;
	int		soma;
	int		media;

	soma = 0;
	cursor = *stack_a;
	while (cursor)
	{
		soma += cursor->content;
		cursor = cursor->next;
	}
	media = soma / ft_lstsize(*stack_a);
	return (media);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*c_b;
	t_list	*spot;

	c_b = *stack_b;
	if (c_b->content > ft_lstlast(*stack_a)->content
		&& last_great(stack_a) == ft_lstlast(*stack_a))
	{
		push(stack_b, stack_a, 2);
		rotate(stack_a, 1);
	}
	else
	{
		spot = find_spot(*stack_a, *stack_b);
		if (ft_cost_r(*stack_a, spot) > ft_cost_rr(spot))
			while (*stack_a != spot)
				reverse_rotate(stack_a, 1);
		else
			while (*stack_a != spot)
				rotate(stack_a, 1);
		push(stack_b, stack_a, 2);
	}
}

void	algo100(t_list **stack_a, t_list **stack_b, int ac)
{
	push_to_b(stack_a, stack_b);
	if (!(ft_issorted(*stack_a)))
		choose_case(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		if (look_the_better(stack_a, stack_b) == 1)
			reverse_rotate(stack_b, 2);
		if (look_the_better(stack_a, stack_a) == 2)
			swap(stack_b, 2);
		push_back_to_a(stack_a, stack_b);
	}
	if (!(ft_issorted(*stack_a)))
		final_sort(stack_a, ac);
}
