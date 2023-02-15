/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:23:34 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:55:08 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len)
		return (size + src_len);
	while (dest[i])
		i++;
	while (src[j] && j + dest_len + 1 < size)
		dest[i++] = src[j++];
	dest[i] = 0;
	if (dest_len < size)
		return (dest_len + src_len);
	return (size + src_len);
}
