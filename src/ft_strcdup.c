/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 04:09:51 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 04:09:52 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcdup(const char *src, char c)
{
	char	*str;
	int		len;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	NULL_CHECK(!(str = (char*)ft_memalloc(len + 1)));
	return (ft_strccpy(str, src, c));
}
