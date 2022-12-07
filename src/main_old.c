/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/05 15:41:59 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	generate_sample_img(t_mlx_data *mlx_data)
{
	int	i, j;
	t_color	*my_color1;
	t_color	*my_color2;
	t_color	*aux;

	my_color1 = create_color(0, 127, 63.5);
	my_color2 = create_color(255, 31.75, 160);
	aux = multiply_color_by_scalar(my_color1, 0.95);
	i = -1;
	j = WINDOW_HEIGHT;
	while (++i < WINDOW_WIDTH)
	{
		while (--j >= 0)
			mlx_data->image.data[WINDOW_WIDTH * j + i] = get_trgb_int(0, j % 255, 0, i % 255);
			//mlx_data->image.data[WINDOW_WIDTH * j + i] = get_trgb_from_color(aux);
		j = WINDOW_HEIGHT;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
	mlx_data->image.img_ptr, 0, 0);
	free(my_color1);
	free(my_color2);
	free(aux);
}

int	main()
{
	t_mlx_data mlx_data;
	minilibx_initialize(&mlx_data);

	generate_sample_img(&mlx_data);
	
	t_matrix *my_matrix = create_matrix(4, 4);
	/*
	my_matrix->values[0][0] = 8;
	my_matrix->values[0][1] = -5;
	my_matrix->values[0][2] = 9;
	my_matrix->values[0][3] = 2;
	my_matrix->values[1][0] = 7;
	my_matrix->values[1][1] = 5;
	my_matrix->values[1][2] = 6;
	my_matrix->values[1][3] = 1;
	my_matrix->values[2][0] = -6;
	my_matrix->values[2][1] = 0;
	my_matrix->values[2][2] = 9;
	my_matrix->values[2][3] = 6;
	my_matrix->values[3][0] = -3;
	my_matrix->values[3][1] = 0;
	my_matrix->values[3][2] = -9;
	my_matrix->values[3][3] = -4;
	*/

	t_matrix *my_matrix2 = get_x_rotation_matrix(PI / 2);
	t_matrix *my_matrix3 = get_scaling_matrix(5, 5, 5);
	t_matrix *my_matrix4 = get_translation_matrix(10, 5, 7);
	t_matrix *my_matrix5 = multiply_matrices(my_matrix4, my_matrix3);
	t_matrix *my_matrix6 = multiply_matrices(my_matrix5, my_matrix2);
	
	
	t_tuple	*tuple = create_point(1, 0, 1);
	t_matrix *my_matrix7 = multiply_matrix_by_tuple(my_matrix6, tuple);
	display_matrix(my_matrix7);
	
	destroy_matrix(my_matrix);
	destroy_matrix(my_matrix2);
	destroy_matrix(my_matrix3);
	destroy_matrix(my_matrix4);
	destroy_matrix(my_matrix5);
	destroy_matrix(my_matrix6);

	
	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}