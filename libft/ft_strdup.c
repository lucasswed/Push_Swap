/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:28:09 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/02/23 09:44:25 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		len;
	int		index;

	if (src)
	{
		index = 0;
		len = ft_strlen(src);
		if (!len)
			return (NULL);
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (src[index])
		{
			str[index] = src[index];
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
