/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:11:46 by jochang           #+#    #+#             */
/*   Updated: 2018/08/20 13:18:44 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pt_uitoa(uint64_t n)
{
	char	*str;
	int		len;

	len = pt_upval(n);
	str = (char*)ft_strnew(len + 1);
	NULL_CHECK(!str);
	IF_TRUE(n == 0, str[0] = '0');
	len--;
	while (n)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
