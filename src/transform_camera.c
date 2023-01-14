/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:26:27 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/14 11:58:41 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	transform_camera(t_camera *camera, t_data *data)
{
	float	new_z;

	destroy_matrix(camera->transform);
	t_tuple *up = create_vector(0,1,0);
	if ((f_equal(dot_product(up, data->cam->vector), 1)) || \
		(f_equal(dot_product(up, data->cam->vector), -1)))
	{
		free(up);
		new_z = (data->cam->vector->y > 0) * (-1) + (data->cam->vector->y < 0);
		up = create_vector(0, 0, new_z);
	}
	t_tuple *to = sum_tuples(data->cam->point, data->cam->vector);
	camera->transform = view_transform(data->cam->point, to, up);
	free(up);
	free(to);
}