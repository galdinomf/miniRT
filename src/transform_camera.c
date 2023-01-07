/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:26:27 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/07 12:28:22 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	transform_camera(t_camera *camera, t_data *data)
{
	destroy_matrix(camera->transform);
	t_tuple *up = create_vector(0,1,0);
	t_tuple *to = sum_tuples(data->cam->point, data->cam->vector);
	camera->transform = view_transform(data->cam->point, to, up);
	free(up);
	free(to);
}