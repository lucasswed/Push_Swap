/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:35:13 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/12/21 11:01:12 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	swap(t_list **stack, int option)
{
	t_list	*cursor;
	t_list	*temp;

	cursor = *stack;
	temp = cursor->next->next;
	cursor = cursor->next;
	cursor->next = *stack;
	*stack = cursor;
	cursor = cursor->next;
	cursor->next = temp;
	if (option == 1)
		write(1, "sa\n", 3);
	if (option == 2)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	write(1, "ss\n", 3);
}
