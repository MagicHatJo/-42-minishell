/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 05:55:04 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 05:55:05 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_path(void)
{
	int		i;

	i = -1;
	while (g_env[++i])
		if (ft_strnequ(g_env[i], "PATH=", 5))
			return (g_env[i]);
	return (NULL);
}

static int		dispatch_mod(char **av, char *path)
{
	pid_t	cpid;
	int		c;

	c = -1;
	cpid = fork();
	g_sigstatus = 1;
	if (cpid == 0)
	{
		if (!check_rights(path))
			exit(0);
		execve(path, av, g_env);
		exit(1);
	}
	else
		wait(&c);
	g_sigstatus = 0;
	return ((c / 255) ^ 1);
}

static char		*path_join(char const *s1, char const *s2)
{
	char	*new;
	int		len;

	NULL_CHECK(!s1 || !s2);
	len = ft_strlen(s1);
	NULL_CHECK(!(new = (char*)ft_memalloc(len + ft_strlen(s2) + 2)));
	ft_strcpy(new, s1);
	new[len] = '/';
	ft_strcat(new, s2);
	return (new);
}

int				dispatch_bin(char **av)
{
	char	**paths;
	char	*tmp;
	int		check;
	int		i;

	check = 0;
	if (!(tmp = get_path()))
		return (0);
	paths = ft_strsplit(&tmp[5], ':');
	i = -1;
	while (paths[++i])
	{
		tmp = path_join(paths[i], av[0]);
		if (dispatch_mod(av, tmp))
		{
			check = 1;
			free(tmp);
			break ;
		}
		free(tmp);
	}
	ft_arrfree(paths);
	return (check);
}
