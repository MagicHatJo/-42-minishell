/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:49:10 by jochang           #+#    #+#             */
/*   Updated: 2018/05/30 23:31:57 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	NULL_CHECK(!s1 || !s2);
	NULL_CHECK(!(new = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)));
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
