/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rendering_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/20 16:25:11 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
/*
int	main(int argc, char **argv)
{
	if (argc !=2)
		error_exit("Error\nArgs invalid\n", 1);
	check_file(argv[1]);
	printf("OK!\n");
}
*/
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
	
	//generate_sample_img(&mlx_data);

	t_elements **elem =	malloc(sizeof(t_elements)*5);
	elem[4] = NULL;
	t_elements *sphere = (t_elements *) malloc(sizeof(t_elements));
	sphere->point = create_point(0,0,0);
	t_matrix *translation = get_translation_matrix(100, 70, 0);
	t_matrix *scaling = get_scaling_matrix(20,20,20);
	sphere->transformation = multiply_matrices(translation, scaling);
	destroy_matrix(translation);
	destroy_matrix(scaling);

	t_material *m = (t_material *) malloc(sizeof(t_material));
	m->color = create_color(1, 0.2, 1);
	m->ambient = 0.1;
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->shininess = 20;
	
	sphere->material = m;
	sphere->type = 4;
	elem[0] = sphere;

	t_elements *plane = (t_elements *) malloc(sizeof(t_elements));
	plane->point = create_point(0,0,0);
	translation = get_translation_matrix(100, 90,10);
	t_matrix *rotation = get_x_rotation_matrix(30);
	plane->transformation = multiply_matrices(translation, rotation);
	destroy_matrix(translation);
	//destroy_matrix(scaling);
	destroy_matrix(rotation);

	t_material *m1 = (t_material *) malloc(sizeof(t_material));
	m1->color = create_color(1, 1, 1);
	m1->ambient = 0.1;
	m1->diffuse = 0.9;
	m1->specular = 0.9;
	m1->shininess = 20;
	
	plane->type = 5;
	plane->material = m1;

	elem[1] = plane;

	t_elements *plane2 = (t_elements *) malloc(sizeof(t_elements));
	plane2->point = create_point(0,0,0);
	translation = get_translation_matrix(100, 90,10);
	rotation = get_x_rotation_matrix(60);
	plane2->transformation = multiply_matrices(translation, rotation);
	destroy_matrix(translation);
	//destroy_matrix(scaling);
	destroy_matrix(rotation);
	
	plane2->type = 5;
	plane2->material = m1;

	elem[2] = plane2;

	t_elements *plane3 = (t_elements *) malloc(sizeof(t_elements));
	plane3->point = create_point(0,0,0);
	translation = get_translation_matrix(100, 90,10);
	rotation = get_x_rotation_matrix(2);
	plane3->transformation = multiply_matrices(translation, rotation);
	destroy_matrix(translation);
	//destroy_matrix(scaling);
	destroy_matrix(rotation);
	
	plane3->type = 5;
	plane3->material = m1;

	elem[3] = plane3;

	t_elements *light = (t_elements *) malloc(sizeof(t_elements));
	light->point = create_point(50, 0, -100);
	light->color = create_color(1, 1, 1);

	t_tuple *origin = create_point(100, 70, -90);
	
	render_elements(elem, light, origin, mlx_data);

	free(origin);
	free(light->point);
	free(light->color);
	free(light);
	free(sphere->point);
	destroy_matrix(sphere->transformation);
	free(m->color);
	free(m);
	free(sphere);

	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}