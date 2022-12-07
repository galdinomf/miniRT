/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:27:14 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/26 14:32:21 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned int	ft_strlen(char *str);

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len_s;

	if (s == NULL)
		return ;
	len_s = ft_strlen(s);
	if (fd != -1)
		write(fd, s, len_s);
}

static unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
