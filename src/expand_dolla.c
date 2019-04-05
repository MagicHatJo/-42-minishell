/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dolla.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:32:37 by jochang           #+#    #+#             */
/*   Updated: 2019/04/01 05:32:37 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	append_env(char *cmd, char *path)
{
	int		i;
	int		k;

	i = 1;
	k = -1;
	while (IS_ALNUM(path[i]))
		i++;
	i--;
	while (g_env[++k])
		if (ft_strnequ(g_env[k], &path[1], i) && g_env[k][i] == '=')
		{
			ft_strcat(cmd, &g_env[k][i + 1]);
			break ;
		}
	return (i);
}

void		expand_dolla(char **s)
{
	char	cmd[CWD_BUF_SIZE];
	char	*tmp;
	int		i;

	ft_bzero(cmd, CWD_BUF_SIZE);
	i = -1;
	while ((*s)[++i])
	{
		if ((*s)[i] == '$')
			i += append_env(&cmd[0], &(*s)[i]);
		else
			ft_strncat(cmd, &(*s)[i], 1);
	}
	tmp = *s;
	*s = ft_strdup(cmd);
	free(tmp);
}
