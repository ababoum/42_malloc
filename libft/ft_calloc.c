/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:32:39 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 21:19:55 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*output;

	if (size == __SIZE_MAX__ || count == __SIZE_MAX__)
		return (0);
	output = malloc(count * size);
	if (!output)
		return (NULL);
	ft_bzero(output, count * size);
	return (output);
}
