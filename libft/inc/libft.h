/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:37:15 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 14:48:47 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <sys/stat.h>
# include <sys/ioctl.h>

# include "get_next_line.h"
# include "ft_printf.h"
# include "macro.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** For ft_getopt
*/
char				*g_optarg;
int					g_optind;
int					g_optopt;

/*
** BIT
*/

uint32_t			ft_swapendian(uint32_t i);
uint32_t			*ft_swapnendian(uint32_t *arr, int32_t n);
uint64_t			ft_swapendian64(uint64_t i);
uint64_t			*ft_swapnendian64(uint64_t *arr, int32_t n);

/*
** CHK
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isdir(const char *path);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_placevalue(int64_t n);
int					ft_wordcount(char const *s, char const c);
int					ft_wordlen(char const *s, char const c);

/*
** CNV
*/

int					ft_atoi(const char *str);
char				*ft_itoa(int64_t n);

/*
** GET
*/

int					ft_getnstdin(int n, char **string);
int					ft_getopt(int argc, char **argv, char *optstring);
char				*ft_getstdin(void);
int					ft_getwincols(void);

/*
** LST
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
** MEM
*/

void				ft_bzero(void *str, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t size);

/*
** PUT
*/

void				ft_printmemory(const void *addr, size_t size,
									int split, int nl);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);

/*
** STR
*/

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strccpy(char *dst, const char *src, char c);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strlower(const char *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strndup(const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str, const char *to_find,
								size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strupper(const char *src);
int					ft_toupper(int c);
int					ft_tolower(int c);

#endif
