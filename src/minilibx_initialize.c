/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:23:49 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 18:39:01 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minilibx.h>

int	minilibx_initialize(t_mlx_data *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		return (MLX_ERROR);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, WINDOW_WIDTH, \
	WINDOW_HEIGHT, "miniRT");
	if (mlx_data->win_ptr == NULL)
		return (MLX_ERROR);
	mlx_data->image.img_ptr = mlx_new_image(mlx_data->mlx_ptr, \
											WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_data->image.data = (int *)mlx_get_data_addr(mlx_data->image.img_ptr, \
	&mlx_data->image.bpp, &mlx_data->image.size_l, &mlx_data->image.endian);
	return (0);
}
