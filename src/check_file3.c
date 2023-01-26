/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:34:42 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/26 18:42:55 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static float	magnitude(float x, float y, float z)
{
	float	mag_sqr;

	mag_sqr = pow(x, 2) + pow(y, 2) + pow(z, 2);
	return (sqrtf(mag_sqr));
}

int	isnormalized(float x, float y, float z)
{
	float	mag;

	mag = magnitude(x, y, z);
	if (fabs(mag - 1) >= EPSILON)
	{
		printf("Vetor not normalized, magnitude = %.3f\n", mag);
		return (0);
	}
	return (1);
}

int	check_cylinder(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isndvector(str[2]) && ft_isfloat(str[3]) \
			&& ft_isfloat(str[4]) && ft_isrgb(str[5]) && !str[6]))
		return (6);
	return (0);
}

int	ft_isndvector(char *str)
{
	int		i;
	char	**split;

	split = ft_split(str, ',');
	i = -1;
	while (split[++i])
	{
		if (!(ft_isfloat(split[i]) || \
				ft_atof(split[i]) < 1 || ft_atof(split[i]) > -1))
		{
			free_split((void *)split);
			return (0);
		}
	}
	if (i != 3 || \
		!isnormalized(ft_atof(split[0]), ft_atof(split[1]), ft_atof(split[2])))
	{
		free_split((void *)split);
		return (0);
	}
	free_split((void *)split);
	return (1);
}
