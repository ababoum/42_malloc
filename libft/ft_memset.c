/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:34:15 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:49:26 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		((char *)ptr)[i++] = val;
	return (ptr);
}
