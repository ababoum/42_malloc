/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:28:47 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:57:55 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	len_to_trim(char const *s, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i] && is_set(s[i], set))
	{
		len++;
		i++;
	}
	if (i == ft_strlen(s))
		return (len);
	else
		i = ft_strlen(s) - 1;
	while (is_set(s[i], set))
	{
		len++;
		i--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trimmed;

	i = 0;
	j = 0;
	trimmed = malloc(ft_strlen(s1) - len_to_trim(s1, set) + 1);
	if (!trimmed)
		return (0);
	while (is_set(s1[i], set))
		i++;
	while (s1[i] && j < ft_strlen(s1) - len_to_trim(s1, set))
		trimmed[j++] = s1[i++];
	trimmed[j] = 0;
	return (trimmed);
}
