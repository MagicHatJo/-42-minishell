/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:56:56 by jochang           #+#    #+#             */
/*   Updated: 2018/04/26 05:38:05 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint8_t	*s1;
	uint8_t	*s2;

	if (n <= 0 || dst == src)
		return (dst);
	s1 = (uint8_t*)dst;
	s2 = (uint8_t*)src;
	while (--n)
		*s1++ = *s2++;
	*s1 = *s2;
	return (dst);
}
