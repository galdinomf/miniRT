/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/03 13:49:35 by mgaldino         ###   ########.fr       */
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

	t_elements *cylinder = (t_elements *) malloc(sizeof(t_elements));
	cylinder->type = CYLINDER;
	cylinder->transformation = get_identity_matrix(4);
	cylinder->point = create_point(-1, 1.5, 3);
	cylinder->prop2 = (float *) malloc(sizeof(float));
	*cylinder->prop2 = 1;
	t_tuple *origin = create_point(0, 1.5, -2);
	t_tuple *unnorm_direction = create_vector(0, 0, 1);
	t_tuple *direction = normalize_tuple(unnorm_direction);
	free(unnorm_direction);
	t_ray *ray = create_ray(origin, direction);
	intersect_cylinder(ray, cylinder);
	
	t_list	*aux = ray->intersections;
	while (aux)
	{
		printf("t = %f\n", ((t_intersection *) aux->content)->t);
		aux = aux->next;
	}
	
	
	t_tuple *normal = get_normal_at_sphere(cylinder, origin);
	printf("normal = (%f, %f, %f)\n", normal->x, normal->y, normal->z);
	
	destroy_ray(ray);
	destroy_matrix(cylinder->transformation);
	free(cylinder->point);
	free(cylinder->prop2);
	free(cylinder);
	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}