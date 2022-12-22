/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:15:48 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/22 14:16:58 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_camera	*create_camera(int hsize, int vsize, float field_of_view)
{
	t_camera	*new_camera;

	new_camera = (t_camera *) malloc(sizeof(t_camera));
	new_camera->hsize = hsize;
	new_camera->vsize = vsize;
	new_camera->field_of_view = field_of_view;
	new_camera->transform = get_identity_matrix(4);
	new_camera->half_height = 0;
	new_camera->half_width = 0;
	new_camera->pixel_size = 0;
	return (new_camera);
}

void	destroy_camera(t_camera *camera)
{
	destroy_matrix(camera->transform);
	free(camera);
}

void	compute_pixel_size(t_camera *camera)
{
	float	half_view;
	float	aspect;

	half_view = tan(camera->field_of_view / 2);
	aspect = (float) camera->hsize / (float) camera->vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / (float) camera->hsize;
}

t_ray	*get_resulting_ray(t_camera *camera, float world_x, float world_y)
{
	t_tuple	*pixel;
	t_tuple	*origin;
	t_tuple	*direction;
	t_tuple	*aux_tuple;
	t_matrix	*aux_matrix;

	aux_matrix = get_inverse_matrix(camera->transform);
	aux_tuple = create_point(world_x, world_y, -1);
	pixel = multiply_matrix_by_tuple(aux_matrix, aux_tuple);
	free(aux_tuple);
	aux_tuple = create_point(0, 0, 0);
	origin = multiply_matrix_by_tuple(aux_matrix, aux_tuple);
	free(aux_tuple);
	aux_tuple = subtract_tuples(pixel, origin);
	direction = normalize_tuple(aux_tuple);
	free(aux_tuple);
	free(pixel);
	destroy_matrix(aux_matrix);
	return (create_ray(origin, direction));
}

t_ray	*ray_for_pixel(t_camera *camera, float px, float py)
{
	float world_x;
	float world_y;

	world_x = camera->half_width  - ((px + 0.5) * camera->pixel_size);
	world_y = camera->half_height - ((py + 0.5) * camera->pixel_size);
	return (get_resulting_ray(camera, world_x, world_y));
}
