/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:20:36 by jochang           #+#    #+#             */
/*   Updated: 2019/03/25 00:20:36 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_home(char *cwd)
{
	int		i;

	i = -1;
	ft_bzero(cwd, CWD_BUF_SIZE);
	while (g_env[++i])
	{
		if (ft_strnequ(g_env[i], "HOME=", 5))
		{
			ft_strcpy(cwd, &g_env[i][5]);
			break ;
		}
	}
}

static void	get_old(char *cwd)
{
	int		i;

	i = -1;
	ft_bzero(cwd, CWD_BUF_SIZE);
	while (g_env[++i])
	{
		if (ft_strnequ(g_env[i], "OLDPWD=", 7))
		{
			ft_strcpy(cwd, &g_env[i][7]);
			break ;
		}
	}
}

static void	get_abs(char *cwd, char *path)
{
	ft_bzero(cwd, CWD_BUF_SIZE);
	ft_strcpy(cwd, path);
}

static void	update_path(char *cwd)
{
	int		old_pwd;
	int		cur_pwd;
	char	*tmp;
	int		i;

	i = -1;
	while (g_env[++i])
	{
		if (ft_strnequ(g_env[i], "OLDPWD=", 7))
			old_pwd = i;
		else if (ft_strnequ(g_env[i], "PWD=", 4))
			cur_pwd = i;
	}
	tmp = g_env[old_pwd];
	g_env[old_pwd] = ft_strjoin("OLDPWD=", &g_env[cur_pwd][4]);
	free(tmp);
	tmp = g_env[cur_pwd];
	ft_bzero(cwd, CWD_BUF_SIZE);
	getcwd(cwd, CWD_BUF_SIZE);
	if (ft_strnequ(cwd, "/private", 8))
		g_env[cur_pwd] = ft_strjoin("PWD=", &cwd[8]);
	else
		g_env[cur_pwd] = ft_strjoin("PWD=", cwd);
	free(tmp);
}

void		d_cd(int ac, char **av)
{
	char	cwd[CWD_BUF_SIZE];

	ft_bzero(cwd, CWD_BUF_SIZE);
	if (ac > 2 || !(getcwd(cwd, CWD_BUF_SIZE)))
	{
		ft_printf("cd: string not in pwd: %s\n", av[1]);
		return ;
	}
	if (ac == 1)
		get_home(&cwd[0]);
	else if (ft_strequ(av[1], "-"))
		get_old(&cwd[0]);
	else if (av[1][0] == '/')
		get_abs(&cwd[0], av[1]);
	else
	{
		ft_strcat(cwd, "/");
		ft_strcat(cwd, av[1]);
	}
	if (chdir(cwd) == -1)
		ft_printf("cd: no such file or directory: %s\n", av[1]);
	else
		update_path(cwd);
}
