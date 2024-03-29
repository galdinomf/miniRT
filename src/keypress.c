/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:58:50 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 18:33:14 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	keypress(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == XK_Escape)
		mlx_loop_end (mlx_data->mlx_ptr);
	return (0);
}
