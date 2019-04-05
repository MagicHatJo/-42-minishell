/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 19:50:44 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 16:34:24 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_flags	get_flags(char **str)
{
	t_flags flags;

	flags.pound = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	while (**str != '\0')
	{
		if (**str == '#')
			flags.pound = 1;
		else if (**str == '0')
			flags.zero = 1;
		else if (**str == '-')
			flags.minus = 1;
		else if (**str == '+')
			flags.plus = 1;
		else if (**str == ' ')
			flags.space = 1;
		else
			break ;
		(*str)++;
	}
	return (flags);
}

static uint32_t	get_width(char **str, va_list ap)
{
	uint32_t	w;

	w = 0;
	if (IS_DIGIT(**str))
	{
		w = ft_atoi(*str);
		while (IS_DIGIT(**str))
			(*str)++;
	}
	else if (**str == '*')
	{
		w = va_arg(ap, int);
		(*str)++;
	}
	return (w);
}

static int32_t	get_precision(char **str, va_list ap)
{
	int32_t	p;

	p = -1;
	if (**str == '.')
	{
		p = 0;
		(*str)++;
		if (IS_DIGIT(**str))
		{
			p = ft_atoi(*str);
			while (IS_DIGIT(**str))
				(*str)++;
		}
		else if (**str == '*')
		{
			p = va_arg(ap, int);
			(*str)++;
		}
	}
	return (p);
}

static uint32_t	get_length(char **str)
{
	uint32_t	l;

	l = 0;
	if (**str == 'h' && *(*str + 1) != 'h')
		l = 104;
	else if (**str == 'h' && *(*str + 1) == 'h')
		l = 208;
	else if (**str == 'l' && *(*str + 1) != 'l')
		l = 108;
	else if (**str == 'l' && *(*str + 1) == 'l')
		l = 216;
	else if (**str == 'j')
		l = 106;
	else if (**str == 'z')
		l = 122;
	if (l > 0)
		(*str) += (l >= 130 ? 2 : 1);
	return (l);
}

t_opts			get_opts(char **str, va_list ap)
{
	t_opts opts;

	opts.flags = get_flags(str);
	opts.width = get_width(str, ap);
	opts.precision = get_precision(str, ap);
	opts.length = get_length(str);
	return (opts);
}
