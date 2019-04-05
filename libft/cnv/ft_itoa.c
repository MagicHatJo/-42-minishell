/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:11:46 by jochang           #+#    #+#             */
/*   Updated: 2018/04/26 01:23:55 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int64_t n)
{
	char	*str;
	int		sign;
	int		len;

	sign = (n >= 0 ? 1 : -1);
	len = ft_placevalue(n) + (sign >= 0 ? 0 : 1);
	str = (char*)ft_strnew(len + 1);
	NULL_CHECK(!str);
	IF_TRUE(n == 0, str[0] = '0');
	len--;
	while (n)
	{
		str[len] = (n % 10) * sign + '0';
		n /= 10;
		len--;
	}
	IF_TRUE(sign == -1, str[len] = '-');
	return (str);
}
