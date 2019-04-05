/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:43:14 by jochang           #+#    #+#             */
/*   Updated: 2018/04/26 05:34:46 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uint8_t	*str1;
	uint8_t	*str2;

	ZERO_CHECK(n <= 0 || s1 == s2);
	str1 = (uint8_t*)s1;
	str2 = (uint8_t*)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
