/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:43:25 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/18 10:43:27 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_tuple	*get_normalized_world_normal(t_matrix *inverse_matrix, \
										t_tuple *object_normal)
{
	t_matrix	*transp_matrix;
	t_tuple		*world_normal;
	t_tuple		*normalized_world_normal;

	transp_matrix = get_transposed_matrix(inverse_matrix);
	world_normal = multiply_matrix_by_tuple(transp_matrix, object_normal);
	world_normal->w = 0;
	normalized_world_normal = normalize_tuple(world_normal);
	free(world_normal);
	destroy_matrix(transp_matrix);
	return (normalized_world_normal);
}

t_tuple	*get_cylinder_normal(t_tuple *object_point, t_elements *cylinder)
{
	float	dist;
	float	y_max;
	float	y_min;
	int		p;

	y_max = cylinder->point->y + (*cylinder->prop2 / 2);
	y_min = cylinder->point->y - (*cylinder->prop2 / 2);
	dist = pow(object_point->x, 2) + pow(object_point->z, 2);
	p = ((!f_equal(dist, 1)) && (dist < 1));
	if (p && ((object_point->y > y_max - EPSILON) || \
		(f_equal(object_point->y, y_max - EPSILON))))
		return (create_vector(0, 1, 0));
	if (p && ((object_point->y > y_min + EPSILON) || \
		(f_equal(object_point->y, y_min + EPSILON))))
		return (create_vector(0, -1, 0));
	return (create_vector(object_point->x, 0, object_point->z));
}

t_tuple	*get_object_normal(t_tuple *object_point, t_elements *shape)
{
	t_tuple		*object_normal;
	t_tuple		*origin_coord;

	if (shape->type == SPHERE)
	{
		origin_coord = create_point(0, 0, 0);
		object_normal = subtract_tuples(object_point, origin_coord);
		free(origin_coord);
	}
	if (shape->type == PLANE)
		object_normal = create_vector(0, 1, 0);
	if (shape->type == CYLINDER)
		object_normal = get_cylinder_normal(object_point, shape);
	return (object_normal);
}

t_tuple	*get_normal(t_elements *sphere, t_tuple *world_point)
{
	t_tuple		*object_point;
	t_matrix	*inverse_matrix;
	t_tuple		*object_normal;
	t_tuple		*normal;

	inverse_matrix = get_inverse_matrix(sphere->transformation);
	object_point = multiply_matrix_by_tuple(inverse_matrix, world_point);
	object_normal = get_object_normal(object_point, sphere);
	normal = get_normalized_world_normal(inverse_matrix, object_normal);
	free(object_point);
	free(object_normal);
	destroy_matrix(inverse_matrix);
	return (normal);
}
