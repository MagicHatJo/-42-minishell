/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:15:45 by jochang           #+#    #+#             */
/*   Updated: 2018/05/18 18:39:17 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*tmp;

	if (!(tmp = (char*)ft_memalloc(size)))
		return (ptr);
	if (ptr)
	{
		ft_memcpy(tmp, ptr, size);
		free(ptr);
	}
	return (tmp);
}
