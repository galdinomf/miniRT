/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:38:06 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/21 16:38:50 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_strlen(char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	len_s;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	result = (char *) malloc((len_s + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

static unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
