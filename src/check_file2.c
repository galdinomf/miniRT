/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:59:57 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/07 00:32:24 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void check_amb_light(char **str)
{
	printf("float? %d\n", ft_isfloat_range(str[1], 0, 1));
	printf("rgb? %d\n", ft_isrgb(str[2]));
	if (!(ft_isfloat_range(str[1], 0, 1) && ft_isrgb(str[2]) && !str[3]))
		error_exit("Error\nWrong data for Ambient Light\n", 1);
}

void check_camera(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isndvector(str[2]) && ft_isfloat_range(str[3], 0, 180) && !str[4]))
		error_exit("Error\nWrong data for camera\n", 1);
} 

void check_light(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isfloat_range(str[2], 0, 1) && ft_isrgb(str[3]) &&!str[4]))
		error_exit("Error\nWrong data for camera\n", 1);
}

void check_sphere(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isfloat(str[2]) && ft_isrgb(str[3]) &&!str[4]))
		error_exit("Error\nWrong data for sphere\n", 1);
}

void check_plane(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isndvector(str[2]) && ft_isrgb(str[3]) &&!str[4]))
		error_exit("Error\nWrong data for sphere\n", 1);
}
