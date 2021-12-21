/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:04:32 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/12/21 16:25:13 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	push(t_list **src, t_list **dest, int option)
{
	t_list	*cursor_src;
	t_list	*cursor_dest;
	t_list	*temp;

	cursor_src = *src;
	cursor_dest = *dest;
	
	if (option == 1)
		write(1, "pb\n", 3);
	if (option == 2)
		write(1, "pa\n", 3);
}