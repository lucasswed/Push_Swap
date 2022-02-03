/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:33:00 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/03 17:20:25 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_small(t_list *stack_a, int *lst, int index)
{
	
}

int	ft_find_median(t_list *stack_a, int ac)
{
	int	index_median;
	int	*list;

	list = malloc(ac * sizeof(int));
	index_median = ac / 2;
	ft_sort(stack_a, ac, &list);
}

static void	ft_sort(t_list *stack_a, int ac, int **list)
{
	t_list	*cursor;
	int		index;

	cursor = stack_a;
	while (cursor)
	{
		while (cursor->content != ft_small(stack_a, list, index))
			cursor = cursor->next;
		list[index] = cursor->content;
		cursor = stack_a;
		index++;
	}
	return (list);
}