/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:46:14 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:56:09 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char				*output;
	unsigned int		i;

	output = malloc(ft_strlen(s) + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		output[i] = f(i, s[i]);
		i++;
	}
	output[i] = 0;
	return (output);
}
