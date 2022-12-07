/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:41:40 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/21 16:43:42 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlcpy(char *dst, const char *src, size_t size);
static size_t	ft_strlen(const char *str);
static int		ft_strcmp(char *s1, char *s2);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	char			str_cmp[10000];
	size_t			len_little;
	size_t			len_big;

	len_little = ft_strlen(little);
	len_big = ft_strlen(big);
	if (len_little == 0)
		return ((char *)big);
	i = 0;
	while ((len - i >= len_little) && (len_big - i >= len_little))
	{
		ft_strlcpy(str_cmp, (big + i), len_little + 1);
		if (ft_strcmp(str_cmp, (char *)little) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			size_src;

	i = 0;
	size_src = ft_strlen(src);
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[size - 1] = '\0';
	return (size_src);
}

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
