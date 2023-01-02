/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_at_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:37:08 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/02 15:19:48 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_tuple	*get_normalized_world_normal(t_matrix *inverse_matrix, t_tuple *object_normal)
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
		object_normal = create_vector(object_point->x, 0, object_point->z);
	return (object_normal);
}

t_tuple	*get_normal_at_sphere(t_elements *sphere, t_tuple *world_point)
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
