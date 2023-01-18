/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:06:30 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 18:20:11 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	do_nothing(void)
{
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
