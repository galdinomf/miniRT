/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/01 14:41:22 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	generate_sample_img(t_mlx_data *mlx_data)
{
	int	i, j;

	i = -1;
	j = WINDOW_HEIGHT;
	while (++i < WINDOW_WIDTH)
	{
		while (--j >= 0)
			mlx_data->image.data[WINDOW_WIDTH * j + i] = get_trgb_int(0, j % 255, 127, i % 255);
		j = WINDOW_HEIGHT;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
	mlx_data->image.img_ptr, 0, 0);
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
	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}