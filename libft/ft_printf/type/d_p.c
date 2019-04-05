/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 12:14:07 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 18:23:48 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if ((opts.flags.pound + opts.flags.zero +
		opts.flags.plus + opts.flags.space) != 0)
	{
		ft_putstr("error: undefined behavior");
		exit(1);
	}
	if (opts.precision != -1)
	{
		ft_putstr("error: undefined behavior");
		exit(1);
	}
	if (opts.length != 0)
	{
		ft_putstr("error: undefined behavior");
		exit(1);
	}
}

static char	*convert(uint64_t p)
{
	int		i;
	char	*s;
	char	*hex;

	NULL_CHECK(!(s = (char*)ft_strnew(14)));
	hex = "0123456789abcdef";
	s[0] = '0';
	s[1] = 'x';
	i = 2;
	if (!p)
		s[2] = '0';
	while (p)
	{
		s[i] = hex[p & 15];
		p >>= 4;
		i++;
	}
	ft_strrev(&s[2]);
	return (s);
}

static char	*padding(char *s, t_opts opts)
{
	char	*str;

	NULL_CHECK(!(str = (char *)ft_strnew(opts.width)));
	ft_memset(str, ' ', opts.width);
	if (opts.flags.minus)
		ft_strncpy(str, s, 14);
	else
		ft_strncpy(&str[opts.width - 14], s, 14);
	free(s);
	return (str);
}

int			d_p(t_opts opts, va_list ap)
{
	uint64_t	p;
	char		*s;
	int			len;

	error_check(opts);
	p = va_arg(ap, uint64_t);
	s = convert(p);
	len = 14;
	if (opts.width > 14)
		s = padding(s, opts);
	ft_putstr(s);
	free(s);
	return (ft_strlen(s));
}
