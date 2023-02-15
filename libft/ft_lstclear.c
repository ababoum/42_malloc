/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:21:45 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:30:49 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp_next;

	tmp = *lst;
	while (tmp)
	{
		tmp_next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = tmp_next;
	}
	*lst = NULL;
}
