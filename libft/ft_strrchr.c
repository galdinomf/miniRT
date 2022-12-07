/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:43:51 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/21 16:44:14 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	int		i;

	if ((unsigned char)c == '\0')
	{
		r = (char *)s + ft_strlen((char *)s);
		return (r);
	}
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			r = (char *)s + i;
			return (r);
		}
		i--;
	}
	return (NULL);
}

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
