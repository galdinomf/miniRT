/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:34:42 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/17 19:30:27 by mgaldino         ###   ########.fr       */
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
	if (mag != 1)
	{
		printf("Vetor not normalized.\n");
		return (0);
	}
	return (1);
}
