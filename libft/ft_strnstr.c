/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:27:04 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:56:36 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;

	i = 0;
	if ((len == 0 && *substr) || len < ft_strlen(substr))
		return (0);
	if (ft_strlen(substr) == 0 && *str)
		return ((char *)str);
	while (str[i] && i + ft_strlen(substr) <= len)
	{
		if (ft_strncmp(str + i, substr, ft_strlen(substr)) == 0)
			return ((char *)str + i);
		i++;
	}
	if (((i == ft_strlen(str) || i == len - ft_strlen(substr) + 1) && \
		ft_strlen(str) != 0) || (i == ft_strlen(str) && ft_strlen(substr) != 0))
		return (0);
	return ((char *)str + i);
}
