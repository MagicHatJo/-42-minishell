/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:19:31 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 00:19:32 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_rights(char *file)
{
	struct stat	s;

	if (lstat(file, &s) == -1)
		return (2);
	if ((s.st_mode & S_IXUSR) || (s.st_mode & S_IXGRP))
		return (1);
	ft_printf("permission denied: %s\n", file);
	return (0);
}
