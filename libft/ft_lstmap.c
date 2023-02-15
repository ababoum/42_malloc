/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:53:45 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:45:23 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;

	(void)del;
	tmp = lst;
	if (!lst)
		return (0);
	new = 0;
	while (tmp)
	{
		ft_lstadd_back(&new, ft_lstnew(f(tmp->content)));
		tmp = tmp->next;
	}
	return (new);
}
