/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:34:43 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 18:45:44 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	render(t_camera *camera, t_data *world, t_mlx_data *mlx_data)
{
	int		i;
	int		j;
	t_ray	*ray;
	t_color	*color;
	int		p;

	j = -1;
	while (++j < camera->vsize)
	{
		i = -1;
		while (++i < camera->hsize)
		{
			p = WINDOW_WIDTH * j + i;
			printf("\r");
			printf("%.0f%%", (((float)(p) / \
								(float)(WINDOW_WIDTH * WINDOW_HEIGHT)) * 100));
			ray = ray_for_pixel(camera, i, j);
			color = color_at(world, ray);
			mlx_data->image.data[p] = get_trgb_from_color(color);
			destroy_ray(ray);
			free(color);
		}
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
	mlx_data->image.img_ptr, 0, 0);
}
