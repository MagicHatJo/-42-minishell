/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:25:17 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 16:18:32 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	uint8_t	*str;

	str = (uint8_t*)s;
	while (n--)
	{
		if (*str == (uint8_t)c)
			return (str);
		str++;
	}
	return (NULL);
}
