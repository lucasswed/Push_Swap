/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:25:07 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/01/25 10:34:36 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_stack(t_list **stack_a, int ac, char **av)
{
	t_list	*cursor;
	int		i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}
//retirar depois
void	print_lst(t_list *lst)
{
	t_list	*cursor;

	cursor = lst;
	while (cursor)
	{
		printf("%d\n", cursor->content);
		cursor = cursor->next;
	}
	printf("-------------\n");
}

static void	call_case(int ac, t_list **stack_a, t_list **stack_b)
{
	if (ac == 3)
		algo2(stack_a);
	else if (ac == 4)
		choose_case(stack_a);
	else if (ac == 6)
		algo5(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (errors(ac, av))
		return (0);
	stack_b = NULL;
	put_stack(&stack_a, ac, av);
//	print_lst(stack_a);
	call_case(ac, &stack_a, &stack_b);
//	print_lst(stack_a);
	return (0);
}
