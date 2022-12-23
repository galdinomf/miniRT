/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:34:43 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/23 14:55:51 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	render(t_camera *camera, t_data *world, t_mlx_data *mlx_data)
{
	int	i;
	int	j;
	t_ray	*ray;
	t_color	*color;

	printf("Rendering...\n");
	i = -1;
	while (++i < camera->hsize)
	{
		j = -1;
		while (++j < camera->vsize)
		{
			ray = ray_for_pixel(camera, i, j);
			color = color_at(world, ray);
			mlx_data->image.data[WINDOW_WIDTH * j + i] = get_trgb_from_color(color);
			destroy_ray(ray);
			free(color);
		}
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
	mlx_data->image.img_ptr, 0, 0);
	printf("Done!\n");
}