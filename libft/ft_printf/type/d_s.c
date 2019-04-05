/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 19:54:50 by jochang           #+#    #+#             */
/*   Updated: 2018/08/23 16:01:29 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if (opts.flags.pound + opts.flags.zero +
		opts.flags.plus + opts.flags.space > 0)
	{
		ft_putstr("error: undefined behavior\n");
		exit(1);
	}
	if (opts.length != 0 && opts.length != 108)
	{
		ft_putstr("error: undefined behavior\n");
		exit(1);
	}
}

static char	*padding(char *s, int size, int len, int left_align)
{
	char	*str;

	NULL_CHECK(!(str = (char*)ft_memalloc(size + 1)));
	ft_memset(str, ' ', size);
	str[size] = '\0';
	if (left_align)
		ft_strncpy(str, s, len);
	else
		ft_strncpy(&str[size - len], s, len);
	free(s);
	return (str);
}

int			d_s(t_opts opts, va_list ap)
{
	char	*s;
	int		len;

	if (opts.length == 108)
	{
		opts.length = 0;
		return (d_us(opts, ap));
	}
	error_check(opts);
	if (!(s = va_arg(ap, char *)))
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	if (opts.precision >= 0)
		len = MIN(len, opts.precision);
	s = ft_strndup(s, len);
	if (opts.width > (uint32_t)len)
		s = padding(s, opts.width, len, opts.flags.minus);
	ft_putstr(s);
	len = ft_strlen(s);
	free(s);
	return (len);
}
