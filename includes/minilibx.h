/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:16:29 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/13 18:45:57 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# define MLX_ERROR 		1
# define WINDOW_WIDTH 	200
# define WINDOW_HEIGHT 	200

# include <stddef.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
}	t_mlx_data;

int		minilibx_initialize(t_mlx_data *mlx_data);
void	minilibx_end(t_mlx_data *mlx_data);
int		get_trgb_int(int t, int r, int g, int b);

#endif
