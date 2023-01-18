/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:37:41 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 18:38:34 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minilibx.h>

void	minilibx_end(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->image.img_ptr);
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	mlx_data->win_ptr = NULL;
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
}
