/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:44:33 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/21 16:46:05 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char *str);
static int		char_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_pos;
	int		end_pos;
	char	*trimmed_str;
	int		len_trimmed_str;
	int		i;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	start_pos = 0;
	while (char_in_set(s1[start_pos], set))
		start_pos++;
	end_pos = ft_strlen((char *)s1) - 1;
	while (char_in_set(s1[end_pos], set))
		end_pos--;
	len_trimmed_str = end_pos - start_pos + 2;
	if (len_trimmed_str < 0)
		len_trimmed_str = 1;
	trimmed_str = (char *) malloc(len_trimmed_str * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len_trimmed_str - 1)
		trimmed_str[i] = s1[start_pos + i];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

static int	char_in_set(char c, char const *set)
{
	int	i;
	int	len_set;

	len_set = ft_strlen((char *)set);
	i = 0;
	while (i < len_set)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
