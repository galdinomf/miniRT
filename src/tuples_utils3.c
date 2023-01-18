/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:00:12 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 19:15:29 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

float	tuple_magnitude(t_tuple *tuple)
{
	float	mag_sqr;

	mag_sqr = pow(tuple->x, 2) + pow(tuple->y, 2) + \
				pow(tuple->z, 2) + pow(tuple->w, 2);
	return (sqrt(mag_sqr));
}

t_tuple	*normalize_tuple(t_tuple *tuple)
{
	float	mag;
	t_tuple	*result;

	mag = tuple_magnitude(tuple);
	result = (t_tuple *) malloc(sizeof(t_tuple));
	result->x = tuple->x / mag;
	result->y = tuple->y / mag;
	result->z = tuple->z / mag;
	result->w = tuple->w / mag;
	return (result);
}

float	dot_product(t_tuple *t1, t_tuple *t2)
{
	float	result;

	result = (t1->x * t2->x) + (t1->y * t2->y) + \
				(t1->z * t2->z) + (t1->w * t2->w);
	return (result);
}

t_tuple	*cross_product(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*result;
	float	x;
	float	y;
	float	z;

	if ((!is_vector(t1)) || (!is_vector(t2)))
		return (NULL);
	x = t1->y * t2->z - t1->z * t2->y;
	y = t1->z * t2->x - t1->x * t2->z;
	z = t1->x * t2->y - t1->y * t2->x;
	result = create_vector(x, y, z);
	return (result);
}
