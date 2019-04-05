/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 06:20:47 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 06:20:50 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_oav(char *cmd)
{
	int		count;
	uint8_t	quotes;

	quotes = 0;
	count = 1;
	while (*cmd)
	{
		if (*cmd == '"')
			quotes ^= 1;
		else if (*cmd == ';' && !quotes)
			count++;
		cmd++;
	}
	return (count);
}

static int	get_next(char *cmd)
{
	int		count;
	uint8_t	quotes;

	quotes = 0;
	count = 0;
	while (cmd[count])
	{
		if (cmd[count] == '"')
			quotes ^= 1;
		if (cmd[count] == ';' && !quotes)
			break ;
		count++;
	}
	return (count);
}

static char	*trim(char *s)
{
	char	*new;
	int		i;
	int		len;
	int		j;

	NULL_CHECK(!s);
	i = 0;
	len = ft_strlen(s);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '"')
		i++;
	while (ft_isspace(s[len]))
		len--;
	if (s[len] == '"')
		len--;
	NULL_CHECK(!(new = (char*)ft_memalloc(len - i >= 0 ? len - i + 1 : 1)));
	j = -1;
	while (++j < len - i)
		new[j] = s[i + j];
	new[j] = '\0';
	return (new);
}

char		**split_cmd(char *cmd)
{
	int		oac;
	char	**oav;
	char	*tmp;
	int		i;
	int		k;

	oac = count_oav(cmd);
	if (!(oav = (char**)ft_memalloc(sizeof(char*) * (oac + 1))))
	{
		ft_printf("Error: Lack of Memory\n");
		return (NULL);
	}
	i = -1;
	while (++i < oac)
	{
		k = get_next(cmd);
		tmp = ft_strndup(cmd, k);
		cmd += k + 1;
		oav[i] = trim(tmp);
		free(tmp);
	}
	return (oav);
}
