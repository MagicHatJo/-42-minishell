/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 04:58:31 by jochang           #+#    #+#             */
/*   Updated: 2019/04/01 04:58:32 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	append_home(char *s)
{
	int		i;

	i = -1;
	while (g_env[++i])
		if (ft_strnequ(g_env[i], "HOME=", 5))
		{
			ft_strcat(s, &g_env[i][5]);
			break ;
		}
}

void		expand_tilde(char **s)
{
	char		cmd[CWD_BUF_SIZE];
	char		*tmp;
	uint8_t		quotes;
	int			i;

	ft_bzero(cmd, CWD_BUF_SIZE);
	quotes = 0;
	i = -1;
	while ((*s)[++i])
	{
		if ((*s)[i] == '"')
			quotes ^= 1;
		if (!quotes && (*s)[i] == '~' && (i == 0 || ft_isspace((*s)[i - 1])))
			append_home(&cmd[0]);
		else
			ft_strncat(cmd, &(*s)[i], 1);
	}
	tmp = *s;
	*s = ft_strdup(cmd);
	free(tmp);
}
