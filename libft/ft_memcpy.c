/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:35:23 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:48:05 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t		i;

	i = 0;
	while (i < count)
	{
		ft_memset(dest + i, ((const char *)src)[i], 1);
		i++;
	}
	return (dest);
}
