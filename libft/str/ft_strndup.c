/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:51:56 by jochang           #+#    #+#             */
/*   Updated: 2018/08/12 12:55:34 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*str;

	NULL_CHECK(!(str = (char*)ft_memalloc(len + 1)));
	return (ft_strncpy(str, src, len));
}
