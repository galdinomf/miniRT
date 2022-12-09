/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:34:42 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/07 19:37:19 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <miniRT.h>

static float	magnitude(float x, float y, float z)
{
	float	mag_sqr;

	mag_sqr = pow(x, 2) + pow(y, 2) + pow(z, 2) ;
	return (sqrtf(mag_sqr));
}

int isnormalized(float x, float y, float z)
{
	float	mag;

	mag = magnitude(x, y, z);
	printf("mag = %.2f\n", mag);
	if (mag != 1)
		return (0);
	return (1);
}
