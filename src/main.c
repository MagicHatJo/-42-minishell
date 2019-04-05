/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:11:01 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 21:11:01 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

uint8_t	g_sigstatus;

static void	handle_sigint(int sig)
{
	(void)sig;
	ft_printf("\n");
	if (!g_sigstatus)
		ft_printf(PROMPT);
}

static void	handler(char **cmd)
{
	int		mac;
	char	**mav;

	expand_dolla(cmd);
	expand_tilde(cmd);
	mac = count_qs(*cmd);
	mav = split_qs(*cmd, mac);
	dispatch_cmd(mac, mav);
	ft_arrfree(mav);
}

int			main(int ac, char **av, char **envp)
{
	char	*cmd;
	int		oac;
	char	**oav;

	(void)ac;
	(void)av;
	cmd = NULL;
	init_env(envp);
	init_auto();
	using_history();
	signal(SIGINT, handle_sigint);
	while (1)
	{
		g_sigstatus = 0;
		cmd ? free(cmd) : 0;
		cmd = ft_readline();
		if (!ft_strequ(cmd, ""))
			add_history(cmd);
		oac = -1;
		oav = expand_semi(cmd);
		while (oav[++oac])
			handler(&oav[oac]);
		ft_arrfree(oav);
	}
	return (0);
}
