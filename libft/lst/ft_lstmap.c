/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:31:01 by jochang           #+#    #+#             */
/*   Updated: 2018/04/26 06:33:50 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_list;

	NULL_CHECK(!lst);
	new = f(lst);
	lst = lst->next;
	begin_list = new;
	while (lst)
	{
		new->next = f(lst);
		new = new->next;
		lst = lst->next;
	}
	return (begin_list);
}
