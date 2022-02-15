/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:33:28 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/15 12:02:12 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_stack(t_list **stack_a, int ac, char **av)
{
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
	else if (ac == 5)
		algo5(stack_a, stack_b);
	else if (ac == 6)
		algo5(stack_a, stack_b);
	else
		algo100(stack_a, stack_b, ac);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (errors(ac, av) || ac < 3)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	put_stack(&stack_a, ac, av);
	call_case(ac, &stack_a, &stack_b);
	return (0);
}
