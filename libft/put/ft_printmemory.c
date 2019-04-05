/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 09:10:06 by jochang           #+#    #+#             */
/*   Updated: 2018/07/05 03:27:58 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printmemory(const void *addr, size_t size, int split, int nl)
{
	char	*hex;
	uint8_t	*x;
	size_t	i;

	hex = "0123456789abcdef";
	i = -1;
	x = (uint8_t*)addr;
	while (++i < size)
	{
		ft_putchar(hex[(x[i] & 0xF0) >> 4]);
		ft_putchar(hex[x[i] & 0x0F]);
		IF_TRUE(split, ft_putchar(' '));
		IF_TRUE(nl && !((i + 1) % nl), ft_putchar('\n'));
	}
}
