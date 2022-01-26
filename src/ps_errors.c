/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:45:48 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/01/17 00:36:27 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_doubles(int ac, char **av)
{
	int	index;
	int	cursor;

	index = 1;
	while (index < ac)
	{
		cursor = index + 1;
		while (cursor < ac)
		{
			if (ft_atoi(av[index]) == ft_atoi(av[cursor]))
				return (1);
			cursor++;
		}
		index++;
	}
	return (0);
}

static int	ft_all_integers(int ac, char **av)
{
	int	index;

	index = 1;
	while (index < ac)
	{
		if (ft_atoi(av[index]) < -2147483648 || ft_atoi(av[index]) > 2147483647)
			return (1);
		index++;
	}
	return (0);
}

static int	ft_is_already_sorted(int ac, char **av)
{
	int	index;

	index = 0;
	while (++index < ac - 1)
	{
		if (ft_atoi(av[index]) >= ft_atoi(av[index + 1]))
			return (0);
		else
			continue ;
	}
	return (1);
}

int	errors(int ac, char **av)
{
	if (ac < 2)
		return (1);
	if (ft_doubles(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_all_integers(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_is_already_sorted(ac, av))
		return (1);
	return (0);
}
