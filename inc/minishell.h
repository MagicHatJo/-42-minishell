/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:29:45 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 20:29:46 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdint.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define PROMPT			"minishell > "
# define GREEN_COLOR	"\033[32m"
# define DEFAULT_COLOR	"\033[0m"
# define GNL_BUFF		2048
# define CWD_BUF_SIZE	4096
# define AUTO_CAP		2048
# define OPT_COUNT		7

/*
** Globals
*/

extern char			**g_env;
extern char			**g_auto;
extern uint8_t		g_sigstatus;

/*
** Functions
*/

void				init_env(char **env);
void				init_auto(void);
char				*ft_readline(void);
int					count_qs(char *cmd);
char				**expand_semi(char *cmd);
void				expand_dolla(char **s);
void				expand_tilde(char **s);
char				**split_cmd(char *cmd);
char				**split_qs(char *cmd, int mac);
int					check_rights(char *file);
void				dispatch_cmd(int mac, char **mav);
int					dispatch_exec(char **av);
int					dispatch_bin(char **av);
int					dispatch_folder(char *s);

/*
** Standard??...
*/

void				ft_putnstr(char *str, int n);
void				ft_arrfree(char **arr);
char				*ft_strcdup(const char *src, char c);

/*
** Dispatch
*/
void				d_cd(int ac, char **av);
void				d_echo(int ac, char **av);
void				d_env(int ac, char **av);
void				d_exit(int ac, char **av);
void				d_history(int ac, char **av);
void				d_setenv(int ac, char **av);
void				d_unsetenv(int ac, char **av);

typedef void		(*t_fun)(int, char **);
typedef struct		s_dis
{
	char			*op;
	t_fun			s;
}					t_dis;

extern const t_dis	g_sel[];

#endif
