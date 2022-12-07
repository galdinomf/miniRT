/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:41:02 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/25 17:12:14 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (i < n))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
