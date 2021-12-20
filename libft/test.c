#include "libft.h"
#include <stdio.h>

void    rotate_a(t_list **stack_a)
{
    t_list *cursor;
    t_list *new_start;

    cursor = ft_lstlast(*stack_a);
    cursor->next = *stack_a;
    cursor = *stack_a;
    new_start = (*stack_a)->next;
    cursor->next = NULL;
    *stack_a = new_start;

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
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    int     i;

    i = 1;
    while (i < argc)
        ft_lstadd_back(&stack_a, ft_lstnew(argv[i++]));
    print_lst(stack_a);
    rotate_a(&stack_a);
    printf("-----------\n");
    print_lst(stack_a);
    return (0);
}