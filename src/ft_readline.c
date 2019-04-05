/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 01:11:19 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 01:11:19 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_next_auto(const char *text, int state)
{
	static int	i;
	static int	len;
	char		*name;

	if (!state)
	{
		i = 0;
		len = ft_strlen(text);
	}
	while ((name = g_auto[i++]))
		if (ft_strnequ(name, text, len))
			return (ft_strdup(name));
	return (NULL);
}

static char	**get_completion(const char *text, int start, int end)
{
	(void)start;
	(void)end;
	rl_attempted_completion_over = 1;
	return (rl_completion_matches(text, get_next_auto));
}

char		*ft_readline(void)
{
	char	*cmd;

	rl_attempted_completion_function = get_completion;
	ft_printf(GREEN_COLOR);
	cmd = readline(PROMPT);
	ft_printf(DEFAULT_COLOR);
	return (cmd);
}
