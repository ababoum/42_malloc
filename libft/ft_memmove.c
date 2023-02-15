/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:13:42 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:48:31 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t		i;
	const char	*tmp_src;
	char		*tmp_dest;

	tmp_src = src;
	tmp_dest = dest;
	if (src < dest)
	{
		i = size;
		while (i > 0)
		{
			i--;
			tmp_dest[i] = tmp_src[i];
		}
	}
	else
	{
		i = 0;
		while (i < size)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}
