/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 19:49:46 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 20:50:46 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	flagged(char **str, va_list ap)
{
	t_opts	opts;
	int		i;
	int		c;

	(*str)++;
	opts = get_opts(str, ap);
	i = -1;
	c = 0;
	while (++i < SPEC_COUNT)
		if (g_select[i].op == **str)
			c = g_select[i].s(opts, ap);
	return (c);
}

static int	normal(char **str)
{
	ft_putchar(**str);
	(*str)++;
	return (1);
}

int			ft_printf(char *str, ...)
{
	int		count;
	va_list ap;

	va_start(ap, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			count += flagged(&str, ap);
			str++;
		}
		else
			count += normal(&str);
	}
	va_end(ap);
	return (count);
}
