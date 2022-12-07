/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:57:04 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/21 15:57:44 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	while (i < n)
	{
		diff = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
