/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/15 14:45:23 by mgaldino         ###   ########.fr       */
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

	t_material *m = (t_material *) malloc(sizeof(t_material));
	m->color = create_color(1, 1, 1);
	m->ambient = 0.1;
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->shininess = 200;
	
	t_tuple	*position = create_point(0,0,0);
	t_tuple	*eyev = create_vector(0,0,-1);
	t_tuple	*normalv = create_vector(0,0,-1);
	
	t_elements *light = (t_elements *) malloc(sizeof(t_elements));
	light->point = create_point(0, 0, 10);
	light->color = create_color(1, 1, 1);

	t_phong_args *args = (t_phong_args *) malloc(sizeof(t_phong_args));
	args->material = m;
	args->light = light;
	args->ilum_point = position;
	args->eyev = eyev;
	args->normalv = normalv;
	t_color *result = get_lighting_color(args);

	printf("result = (%f, %f, %f)\n", result->red, result->green, result->blue);

	free(m->color);
	free(m);
	free(position);
	free(eyev);
	free(normalv);

	free(light->point);
	free(light->color);
	free(light);

	free(args);
	free(result);
	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}