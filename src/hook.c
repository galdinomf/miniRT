/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:06:30 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/25 11:28:54 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	do_nothing(t_mlx_data *mlx_data)
{
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
	mlx_data->image.img_ptr, 0, 0);
	return (0);
}

int	handle_mouserelease(t_mlx_data *mlx_data)
{
	mlx_loop_end (mlx_data->mlx_ptr);
	return (0);
}

void	hook(t_mlx_data *mlx_data)
{
	mlx_loop_hook(mlx_data->mlx_ptr, &do_nothing, mlx_data);
	mlx_hook(mlx_data->win_ptr, KeyPress, KeyPressMask, &keypress, mlx_data);
	mlx_hook(mlx_data->win_ptr, DestroyNotify, 0, \
				&handle_mouserelease, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
