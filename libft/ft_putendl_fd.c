/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:25:26 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/26 14:31:22 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned int	ft_strlen(char *str);

void	ft_putendl_fd(char *s, int fd)
{
	int	len_s;

	if (s == NULL)
		return ;
	len_s = ft_strlen(s);
	if (fd != -1)
	{
		write(fd, s, len_s);
		write(fd, "\n", 1);
	}
}

static unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
