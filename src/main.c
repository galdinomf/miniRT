/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/21 09:03:16 by mgaldino         ###   ########.fr       */
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


	///////////// create light //////////////
	t_elements *light = (t_elements *) malloc(sizeof(t_elements));
	light->type = LIGHT;
	light->point = create_point(-10, 10, -10);
	light->color = create_color(1, 1, 1);
	///////////// create material //////////////	
	t_material *m = (t_material *) malloc(sizeof(t_material));
	m->color = create_color(0.8, 1, 0.6);
	m->ambient = 0.1;
	m->diffuse = 0.7;
	m->specular = 0.2;
	m->shininess = 20;
	///////////// create spheres //////////////
	t_elements *s1 = (t_elements *) malloc(sizeof(t_elements));
	s1->type = SPHERE;
	s1->point = create_point(0,0,0);
	s1->material = m;
	s1->transformation = get_identity_matrix(4);
	t_elements *s2 = (t_elements *) malloc(sizeof(t_elements));
	s2->type = SPHERE;
	s2->point = create_point(0,0,0);
	s2->material = m;
	s2->transformation = get_scaling_matrix(0.5,0.5,0.5);
	///////////// create data //////////////
	t_data	*world = (t_data *) malloc(sizeof(t_data));
	world->n_elem = 3;
	t_elements **elements = (t_elements **) malloc(3 * sizeof(t_elements *));
	elements[0] = s1;
	elements[1] = s2;
	elements[2] = light;
	world->elem = elements;
	




	free(m->color);
	free(m);
	free(s1->point);
	destroy_matrix(s1->transformation);
	free(s1);
	free(s2->point);
	destroy_matrix(s2->transformation);
	free(s2);
	free(light->point);
	free(light->color);
	free(light);
	free(elements);
	free(world);
	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}