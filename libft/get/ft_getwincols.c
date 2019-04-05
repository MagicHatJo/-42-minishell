/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwincols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 22:15:10 by jochang           #+#    #+#             */
/*   Updated: 2019/03/22 22:15:12 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getwincols(void)
{
	struct winsize size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return (size.ws_col);
}
