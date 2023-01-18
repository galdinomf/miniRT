/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:59:57 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/17 19:32:24 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	check_amb_light(char **str)
{
	if (!(ft_isfloat_range(str[1], 0, 1) && ft_isrgb(str[2]) && !str[3]))
		return (1);
	return (0);
}

int	check_camera(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isndvector(str[2]) && \
			ft_isfloat_range(str[3], 0, 180) && !str[4]))
		return (2);
	return (0);
}

int	check_light(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isfloat_range(str[2], 0, 1) \
			&& ft_isrgb(str[3]) &&!str[4]))
		return (3);
	return (0);
}

int	check_sphere(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isfloat(str[2]) && \
			ft_isrgb(str[3]) &&!str[4]))
		return (4);
	return (0);
}

int	check_plane(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isndvector(str[2]) && \
			ft_isrgb(str[3]) &&!str[4]))
		return (5);
	return (0);
}
