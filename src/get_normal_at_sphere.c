/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_at_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:37:08 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/21 10:58:33 by daeidi-h         ###   ########.fr       */
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


t_tuple	*get_normal_at_sphere(t_elements *sphere, t_tuple *world_point)
{
	t_tuple		*object_point;
	t_matrix	*inverse_matrix;
	t_tuple		*object_normal;
	t_tuple		*origin_coord;
	t_tuple		*normal;

	inverse_matrix = get_inverse_matrix(sphere->transformation);
	object_point = multiply_matrix_by_tuple(inverse_matrix, world_point);
	origin_coord = create_point(0, 0, 0);
	if(sphere->type == 4)
		object_normal = subtract_tuples(object_point, origin_coord);
	else
		object_normal = create_point(0, 1, 0);
	normal = get_normalized_world_normal(inverse_matrix, object_normal);
	free(object_point);
	free(origin_coord);
	free(object_normal);
	destroy_matrix(inverse_matrix);
	return (normal);
}
