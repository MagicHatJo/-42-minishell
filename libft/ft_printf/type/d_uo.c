/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_uo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:59:38 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 18:28:12 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		error_check(t_opts opts)
{
	(void)opts;
}

static uint64_t	get_num(uint32_t length, va_list ap)
{
	uint64_t	n;

	n = 0;
	if (length == 104 || length == 208 || length == 108)
		n = va_arg(ap, uint32_t);
	else if (length == 0 || length == 216)
		n = va_arg(ap, uint64_t);
	else if (length == 106)
		n = va_arg(ap, uintmax_t);
	else if (length == 122)
		n = va_arg(ap, size_t);
	return (n);
}

static char		*pound(char *s)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	NULL_CHECK(!(str = (char*)ft_strnew(len + 1)));
	str[0] = '0';
	ft_strncpy(&str[1], s, len);
	free(s);
	return (str);
}

static char		*padding(char *s, int len, t_opts opts)
{
	char	*str;

	NULL_CHECK(!(str = (char*)ft_strnew(opts.width)));
	ft_memset(str, ' ', opts.width);
	if (opts.flags.minus)
		ft_strncpy(str, s, len);
	else
		ft_strncpy(&str[opts.width - len], s, len);
	free(s);
	return (str);
}

int				d_uo(t_opts opts, va_list ap)
{
	uint64_t	n;
	char		*s;
	int			len;

	error_check(opts);
	n = get_num(opts.length, ap);
	s = pt_itoo(n);
	if (opts.flags.pound && n)
		s = pound(s);
	len = ft_strlen(s);
	if (opts.width > (uint32_t)len)
		s = padding(s, len, opts);
	ft_putstr(s);
	len = ft_strlen(s);
	free(s);
	return (len);
}
