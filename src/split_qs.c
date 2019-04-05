/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_qs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:46:52 by jochang           #+#    #+#             */
/*   Updated: 2019/03/31 21:46:52 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	skip_spaces(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (!ft_isspace(s[i]))
			break ;
	return (i);
}

static int	to_next(char *s)
{
	int		i;
	uint8_t	quotes;

	i = -1;
	quotes = 0;
	while (s[++i])
	{
		if (s[i] == '"')
			quotes ^= 1;
		if (!quotes && ft_isspace(s[i]))
			break ;
	}
	return (i);
}

char		**split_qs(char *cmd, int mac)
{
	int		i;
	int		s;
	int		e;
	char	**mav;

	NULL_CHECK(!(mav = (char**)ft_memalloc(sizeof(char*) * (mac + 1))));
	i = 0;
	s = 0;
	while (i < mac)
	{
		s += skip_spaces(&cmd[s]);
		e = to_next(&cmd[s]);
		if (cmd[s] == '"' && cmd[s + e - 1] == '"')
			mav[i] = ft_strndup(&cmd[s + 1], e - 2);
		else
			mav[i] = ft_strndup(&cmd[s], e);
		s += e;
		i++;
	}
	return (mav);
}
