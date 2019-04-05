/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:02:45 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 18:22:16 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		error_check(t_opts opts)
{
	if (opts.flags.pound != 0)
	{
		ft_putstr("error: undefined behavior\n");
		exit(1);
	}
	if (opts.length != 104 && opts.length != 208 &&
		opts.length != 108 && opts.length != 216 &&
		opts.length != 106 && opts.length != 122 &&
		opts.length != 0)
	{
		ft_putstr("error: undefined behavior\n");
		exit(1);
	}
}

static int64_t	get_num(uint32_t length, va_list ap)
{
	int64_t	n;

	n = 0;
	if (length == 0 || length == 104 || length == 208 || length == 108)
		n = va_arg(ap, int);
	else if (length == 216)
		n = va_arg(ap, int64_t);
	else if (length == 106)
		n = va_arg(ap, intmax_t);
	else if (length == 122)
		n = va_arg(ap, size_t);
	return (n);
}

static char		*pad_precision(char *s, int n, int precision)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	if (len >= precision && !(precision == 0 && n == 0))
		return (s);
	NULL_CHECK(!(str = (char*)ft_memalloc(precision + 1)));
	str = ft_memset(str, '0', precision);
	str[precision] = '\0';
	if (precision > len)
		ft_memcpy(&str[precision - len], &s[0], len);
	free(s);
	return (str);
}

static char		*padding(char *s, t_opts opts, int neg)
{
	char	*str;
	int		len;
	int		l;

	len = ft_strlen(s) + ((neg || opts.flags.plus || opts.flags.space) ? 1 : 0);
	len = ((uint32_t)len > opts.width ? len : opts.width);
	NULL_CHECK(!(str = (char*)ft_memalloc(len + 1)));
	ft_memset(str, (opts.flags.zero && opts.precision == -1 ? '0' : ' '), len);
	str[len] = '\0';
	l = ft_strlen(s);
	if (opts.flags.minus)
		ft_strncpy(&str[neg], s, l);
	else
		ft_strncpy(&str[len - l], s, l);
	if (neg)
		str[(opts.flags.minus || opts.flags.zero ? 0 : len - l - 1)] = '-';
	else if (opts.flags.plus)
		str[(opts.flags.minus || opts.flags.zero ? 0 : len - l - 1)] = '+';
	else if (opts.flags.space)
		str[0] = ' ';
	free(s);
	return (str);
}

int				d_d(t_opts opts, va_list ap)
{
	int64_t	n;
	char	*s;
	int		len;
	int		neg;

	error_check(opts);
	n = get_num(opts.length, ap);
	neg = (n < 0 ? 1 : 0);
	s = pt_itoa_abs(n);
	s = pad_precision(s, n, opts.precision);
	s = padding(s, opts, neg);
	ft_putstr(s);
	len = ft_strlen(s);
	free(s);
	return (len);
}
