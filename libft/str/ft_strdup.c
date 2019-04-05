/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 00:18:18 by jochang           #+#    #+#             */
/*   Updated: 2018/06/06 20:06:39 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;

	NULL_CHECK(!(str = (char*)ft_memalloc(ft_strlen(src) + 1)));
	return (ft_strcpy(str, src));
}
