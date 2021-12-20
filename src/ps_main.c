/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:25:07 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/12/20 14:29:30 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void    reverse_rotate(t_list **stack, int option);

void    put_stack(t_list **stack_a, int ac, char **av)
{
    t_list  *cursor;
    int     i;

    i = 1;
    while (i < ac)
    {
        ft_lstadd_back(stack_a, ft_lstnew(av[i]));
        i++;
    }
}

void    print_lst(t_list *lst)
{
    t_list *cursor;

    cursor = lst;
    while (cursor)
    {
        printf("%s\n", cursor->content);
        cursor = cursor->next;
    }
    printf("-------------\n");
}

int main(int ac, char **av)
{
    t_list  *stack_a;
    
    put_stack(&stack_a, ac, av);
    print_lst(stack_a);
    reverse_rotate(&stack_a, 1);
    print_lst(stack_a);
    return(0);
}