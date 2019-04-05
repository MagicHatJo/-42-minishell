/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:50:19 by jochang           #+#    #+#             */
/*   Updated: 2018/04/24 11:39:14 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char			*d;
	const char		*s;
	size_t			dsize;
	size_t			dlen;

	d = dst;
	s = src;
	dsize = dstsize;
	while (dsize-- != 0 && *d)
		d++;
	dlen = d - dst;
	dsize = dstsize - dlen;
	if (dsize == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (dsize != 1)
		{
			*d++ = *s;
			dsize--;
		}
		s++;
	}
	*d = '\0';
	return (s - src + dlen);
}
