/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:31:03 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/21 16:31:23 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(char *str);

char	*ft_strchr(const char *s, int c)
{
	char	*r;
	int		i;

	i = 0;
	if ((unsigned char)c == '\0')
	{
		r = (char *)s + ft_strlen((char *)s);
		return (r);
	}
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			r = (char *)s + i;
			return (r);
		}
		i++;
	}
	return (NULL);
}

static size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
