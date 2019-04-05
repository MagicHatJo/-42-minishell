/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:05:25 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 16:29:05 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pt_itoh(uint64_t n, int caps)
{
	int		i;
	char	*s;
	char	*hex;

	NULL_CHECK(!(s = (char*)ft_strnew(8)));
	hex = (caps ? "0123456789ABCDEF" : "0123456789abcdef");
	i = (n == 0 ? 1 : 0);
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[i] = hex[n & 15];
		n >>= 4;
		i++;
	}
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}
