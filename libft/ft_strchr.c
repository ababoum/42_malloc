/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:24:08 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:53:27 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	c = (unsigned char)c;
	tmp = (char *)str;
	while (i <= ft_strlen(str))
	{
		if (tmp[i] == c)
			return (tmp + i);
		if (tmp[i] && !tmp[i + 1] && !c)
			return (tmp + i + 1);
		i++;
	}
	return (NULL);
}
