/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_auto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 03:08:15 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 03:08:15 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_auto;

static char	*get_path(void)
{
	int		i;

	i = -1;
	while (g_env[++i])
		if (ft_strnequ(g_env[i], "PATH=", 5))
			return (&g_env[i][5]);
	return (NULL);
}

static void	get_all(char *path, int *auto_ind)
{
	struct dirent	*de;
	DIR				*dr;

	if ((dr = opendir(path)))
	{
		while ((de = readdir(dr)))
		{
			if (*auto_ind == AUTO_CAP - 1)
				break ;
			if (de->d_name[0] != '.')
			{
				g_auto[*auto_ind] = ft_strdup(de->d_name);
				(*auto_ind)++;
			}
		}
		closedir(dr);
	}
}

static int	add_builtins(void)
{
	g_auto[0] = ft_strdup("cd");
	g_auto[1] = ft_strdup("echo");
	g_auto[2] = ft_strdup("env");
	g_auto[3] = ft_strdup("exit");
	g_auto[4] = ft_strdup("history");
	g_auto[5] = ft_strdup("setenv");
	g_auto[6] = ft_strdup("unsetenv");
	return (7);
}

void		init_auto(void)
{
	char	**paths;
	int		i;
	int		auto_ind;

	g_auto = (char**)ft_memalloc(sizeof(char*) * AUTO_CAP);
	paths = ft_strsplit(get_path(), ':');
	i = -1;
	auto_ind = add_builtins();
	while (paths[++i])
	{
		if (auto_ind == AUTO_CAP - 1)
			break ;
		get_all(paths[i], &auto_ind);
	}
	ft_arrfree(paths);
}
