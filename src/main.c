/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 19:20:10 by mgaldino         ###   ########.fr       */
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
	t_tuple	*t1 = create_vector(1, 2, 3);
	t_tuple	*t2 = create_vector(4.5, 3.4, -0.5);
	printf("t1 dot t2 = %f\n", dot_product(t1, t2));
	t_tuple *t3 = cross_product(t1, t2);
	printf("t1 cross t2 = (%f, %f, %f)\n", t3->x, t3->y, t3->z);
	free(t1);
	free(t2);
	free(t3);
	t_mlx_data mlx_data;
	minilibx_initialize(&mlx_data);

	generate_sample_img(&mlx_data);
	
	t_matrix *my_matrix = create_matrix(4, 4);
	my_matrix->values[0][0] = -2;
	my_matrix->values[0][1] = -8;
	my_matrix->values[0][2] = 3;
	my_matrix->values[0][3] = 5;
	my_matrix->values[1][0] = -3;
	my_matrix->values[1][1] = 1;
	my_matrix->values[1][2] = 7;
	my_matrix->values[1][3] = 3;
	my_matrix->values[2][0] = 1;
	my_matrix->values[2][1] = 2;
	my_matrix->values[2][2] = -9;
	my_matrix->values[2][3] = 6;
	my_matrix->values[3][0] = -6;
	my_matrix->values[3][1] = 7;
	my_matrix->values[3][2] = 7;
	my_matrix->values[3][3] = -9;
	printf("det of matrix = %f\n", determinant_nd_square_matrix(my_matrix));
	//my_matrix->values[1][2] = 8;
	//my_matrix->values[1][3] = -20;
	t_matrix *my_matrix3 = get_submatrix(my_matrix, 2, 1);
	display_matrix(my_matrix3);
	t_matrix *my_matrix2 = create_matrix(1, 2);
	my_matrix2->values[0][0] = -1;
	my_matrix2->values[0][1] = 5;
	printf("matrix are equal = %d\n", matrices_are_equal(my_matrix, my_matrix2));

	t_matrix *matrix4 = get_identity_matrix(4);
	//display_matrix(matrix4);

	t_tuple	*tuple = create_point(1, 2, 3);

	

	
	free(tuple);
	destroy_matrix(my_matrix);
	destroy_matrix(my_matrix2);
	destroy_matrix(my_matrix3);
	destroy_matrix(matrix4);

	
	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}