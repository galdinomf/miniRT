/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:55:19 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/06 20:12:41 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	error_exit(const char *s, int i)
{
	write(2, s, ft_strlen((char *)s));
	// free every thing
	if (i)
		exit(i);
	exit(0);
}