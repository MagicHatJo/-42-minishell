/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:08:05 by jochang           #+#    #+#             */
/*   Updated: 2018/04/22 00:15:32 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	uint8_t	*s1;
	uint8_t	*s2;

	s1 = (uint8_t*)dst;
	s2 = (uint8_t*)src;
	while (n--)
		if ((*s1++ = *s2++) == (uint8_t)c)
			return (s1);
	return (NULL);
}
