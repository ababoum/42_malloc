/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:28:22 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:58:06 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	sub_len;

	i = 0;
	if (ft_strlen(s) - start > len)
		sub_len = len;
	else
		sub_len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	substr = malloc(sub_len + 1);
	if (!substr)
		return (NULL);
	while (i < sub_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
