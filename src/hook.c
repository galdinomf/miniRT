/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:06:30 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/01 14:42:12 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

//int	do_nothing(t_mlx_data *mlx_data)
int	do_nothing()
{
	//printf("doing nothing %p\n", mlx_data);
	return (0);
}

int	handle_mouserelease(t_mlx_data *mlx_data)
{
//	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->image.img_ptr);
//	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
//	mlx_data->win_ptr = NULL;
	mlx_loop_end (mlx_data->mlx_ptr);
	return (0);
}

void	hook(t_mlx_data *mlx_data)
{
	mlx_loop_hook(mlx_data->mlx_ptr, &do_nothing, mlx_data);
	mlx_hook(mlx_data->win_ptr, KeyPress, KeyPressMask, &keypress, mlx_data);
	mlx_hook(mlx_data->win_ptr, DestroyNotify, 0, &handle_mouserelease, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
