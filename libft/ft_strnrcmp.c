/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:46:54 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/06 00:51:33 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnrcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (n == 0)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	while (s1[--i] == s2[--j] && i >= 0 && j >= 0)
	{
		n--;
		if (n == 0)
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[j]));
}