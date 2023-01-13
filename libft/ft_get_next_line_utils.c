/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:42:09 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/12 14:25:54 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;
	size_t			len_s;
	size_t			len_new_str;

	i = -1;
	while (s[++i])
		;
	len_s = i;
	if (start > len_s)
		len_new_str = 0;
	else if ((len_s - start) >= len)
		len_new_str = (len);
	else
		len_new_str = (len_s - start);
	new_str = (char *) malloc((len_new_str + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len_new_str)
		new_str[i] = s[start + i];
	new_str[i] = '\0';
	return (new_str);
}

int	ft_initialize_and_get_line(int fd, char *buf, char **acc)
{
	int	bytes_read;

	buf[0] = 0;
	if (!*acc)
	{
		*acc = (char *) malloc(BUFFER_SIZE + 1);
		*acc[0] = 0;
	}
	bytes_read = 1;
	while (!ft_char_in_buffer('\n', *acc) && (bytes_read > 0))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read > 0)
			buf[bytes_read] = 0;
		*acc = ft_accumulate_buffer(*acc, buf, bytes_read);
	}
	free (buf);
	return (bytes_read);
}

int	ft_char_in_buffer(char c, char *acc)
{
	int	i;

	i = 0;
	while (acc[i])
	{
		if (acc[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_accumulate_buffer(char *acc, char *buf, int bytes_read)
{
	int		len_acc;
	char	*result;
	int		i;

	if (bytes_read <= 0)
		return (acc);
	len_acc = -1;
	while (acc[++len_acc])
		;
	result = (char *) malloc(len_acc + bytes_read + 1);
	i = -1;
	while (acc[++i])
	{
		result[i] = acc[i];
		acc[i] = 0;
	}	
	free(acc);
	acc = NULL;
	i = -1;
	while (++i < bytes_read)
	{
		result[len_acc + i] = buf[i];
	}
	result[len_acc + i] = '\0';
	return (result);
}

char	*ft_extract_remainder_bytes_from_line(char *acc)
{
	int		i;
	int		remaining_bytes;
	int		j;
	char	*result;

	i = -1;
	while ((acc[++i]) && (acc[i] != '\n'))
		;
	remaining_bytes = 0;
	j = -1;
	i++;
	while ((acc[i - 1]) && (acc[i + ++j]))
		++remaining_bytes;
	result = (char *) malloc(remaining_bytes + 1);
	result[remaining_bytes] = 0;
	j = -1;
	while ((acc[i - 1]) && (acc[i + ++j]))
		result[j] = acc[i + j];
	i = -1;
	while (acc[++i])
		acc[i] = 0;
	free(acc);
	acc = NULL;
	return (result);
}
