/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rendering_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/15 20:38:43 by mgaldino         ###   ########.fr       */
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

	
	t_elements *sphere = (t_elements *) malloc(sizeof(t_elements));
	sphere->point = create_point(0,0,0);
	t_matrix *translation = get_translation_matrix(100, 100, 100);
	t_matrix *scaling = get_scaling_matrix(100,100,100);
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
	
	t_elements *light = (t_elements *) malloc(sizeof(t_elements));
	light->point = create_point(50, 50, -100);
	light->color = create_color(1, 1, 1);


	
//	int	c = 0;
	int	i = -1;
	int	j = -1;
	while (++i < WINDOW_WIDTH)
	{
		while (++j < WINDOW_HEIGHT)
		{
			t_tuple *origin = create_point(100, 100, -50);
			t_tuple	*pixel_point = create_point(i, j, 0);
			t_tuple	*unnormalized_direction = subtract_tuples(pixel_point, origin);
			t_tuple *direction = normalize_tuple(unnormalized_direction);
			
			t_ray *ray = create_ray(origin, direction);
			intersect_sphere(ray, sphere);
				//printf("#%d ", ++c);
			if (ray->intersections)
			{
				//printf("i = %d, j = %d\n", i, j);
				t_intersection *aux = get_hit(ray);
				if (aux)
				{
					float t = aux->t;
				t_tuple *painted_direction = multiply_tuple_by_scalar(direction, t);
				t_tuple	*painted_point = sum_tuples(origin, painted_direction);
				t_tuple	*normal = get_normal_at_sphere(sphere, painted_point);
				t_tuple	*eye_vec = neg_tuple(ray->direction);

				t_phong_args *args = (t_phong_args *) malloc(sizeof(t_phong_args));
				args->material = m;
				args->light = light;
				args->ilum_point = painted_point;
				args->eyev = eye_vec;
				args->normalv = normal;
				
				t_color	*pixel_color = get_lighting_color(args);
				t_color	*pixel_color2 = multiply_color_by_scalar(pixel_color, 255);
				if (pixel_color2->red > 255)
					pixel_color2->red = 255;
				if (pixel_color2->green > 255)
					pixel_color2->green = 255;
				if (pixel_color2->blue > 255)
					pixel_color2->blue = 255;
				//float	x = painted_point->x;
				//float	y = painted_point->y;
				if ((i < WINDOW_WIDTH) && (j < WINDOW_HEIGHT))
					//mlx_data.image.data[WINDOW_WIDTH * j + i] = get_trgb_int(0, 255, 0, 0);
				{
					int	trgb = get_trgb_from_color(pixel_color2);
					mlx_data.image.data[WINDOW_WIDTH * j + i] = trgb;
					if ((pixel_color2->red > 255) || (pixel_color2->green > 255) || (pixel_color2->blue > 255))
					printf("pixel_color = (%f, %f, %f)\n", pixel_color->red, pixel_color->green, pixel_color->blue);
				}

				free(painted_direction);
				free(painted_point);
				free(normal);
				free(eye_vec);
				free(pixel_color);
				free(pixel_color2);
				free(args);
				}
			}
			destroy_ray(ray);
			free(pixel_point);
			free(unnormalized_direction);
		}
		j = -1;
	}				
				mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.win_ptr, \
				mlx_data.image.img_ptr, 0, 0);

	free(light->point);
	free(light->color);
	free(light);
	free(sphere->point);
	destroy_matrix(sphere->transformation);
	free(m->color);
	free(m);
	free(sphere);
	/*
	printf("ray->intersections = %p\n", ray->intersections);
	if (ray->intersections)
	{
		printf("intersections = (%f, %f)\n", ((t_intersection *) ray->intersections->content)->t, ((t_intersection *) ray->intersections->next->content)->t);

		printf("hit = (%f)\n", get_hit(ray)->t);
	printf("intersections->count = %d\n", ft_lstsize(ray->intersections));
	}
	*/
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}