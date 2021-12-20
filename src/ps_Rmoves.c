/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_Rmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:20:44 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/12/20 13:45:30 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void    rotate(t_list **stack, int option)
{
    t_list *cursor;
    t_list *new_start;

    cursor = ft_lstlast(*stack);
    cursor->next = *stack;
    cursor = *stack;
    new_start = (*stack)->next;
    cursor->next = NULL;
    *stack = new_start;
    if (option == 1)
        write(1, "ra", 2);
    if (option == 2)
        write(1, "rb", 2);
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a, 0);
    rotate(stack_b, 0);
    write(1, "rr", 2);
}

void    reverse_rotate(t_list **stack, int option)
{
    t_list  *cursor;
    t_list  *new_end;
    
    cursor = *stack;
    while (new_end != ft_lstlast(cursor))
    {
        new_end = cursor;
        cursor = cursor->next;
    }
    
    cursor = ft_lstlast(cursor);
    cursor->next = *stack;
    *stack = cursor;

}