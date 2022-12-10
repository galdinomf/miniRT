/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/10 13:12:15 by mgaldino         ###   ########.fr       */
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

	generate_sample_img(&mlx_data);
	

	t_tuple *origin = create_point(1, 2, 3);
	t_tuple *direction = create_vector(0, 1, 0);	
	t_ray *ray = create_ray(origin, direction);
	
	t_elements *sphere = (t_elements *) malloc(sizeof(t_elements));
	sphere->point = create_point(0,0,0);

	intersect_sphere(ray, sphere);
	free(sphere->point);
	free(sphere);
	printf("ray->intersections = %p\n", ray->intersections);
	if (ray->intersections)
	{
		printf("intersections = (%f, %f)\n", ((t_intersection *) ray->intersections->content)->t, ((t_intersection *) ray->intersections->next->content)->t);

		printf("hit = (%f)\n", get_hit(ray)->t);
	printf("intersections->count = %d\n", ft_lstsize(ray->intersections));
	}

	t_matrix *transf_matrix = get_scaling_matrix(2,3,4);
	t_ray *transf_ray = transform_ray(ray, transf_matrix);
	printf("transf_ray->origin = (%f, %f, %f)\n", transf_ray->origin->x, transf_ray->origin->y, transf_ray->origin->z);
	printf("transf_ray->direction = (%f, %f, %f)\n", transf_ray->direction->x, transf_ray->direction->y, transf_ray->direction->z);
	
	destroy_ray(ray);
	destroy_ray(transf_ray);
	destroy_matrix(transf_matrix);
	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}