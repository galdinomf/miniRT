/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:47:24 by mgaldino          #+#    #+#             */
/*   Updated: 2022/05/15 20:17:23 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;
	size_t			len_s;
	size_t			len_new_str;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	i = 0;
	if (start > len_s)
		len_new_str = 0;
	else if ((len_s - start) >= len)
		len_new_str = (len);
	else
		len_new_str = (len_s - start);
	new_str = (char *) malloc((len_new_str + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < len_new_str)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
