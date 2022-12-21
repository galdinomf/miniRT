/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:20:58 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/21 10:22:29 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_comps	*get_phong_args(t_elements *sphere, t_ray *ray, float t_value)
{
	t_tuple *painted_direction;
	t_tuple	*painted_point;
	t_tuple	*normal;
	t_tuple	*eye_vec;
	t_comps *args;
	
	painted_direction = multiply_tuple_by_scalar(ray->direction, t_value);
	painted_point = sum_tuples(ray->origin, painted_direction);
	normal = get_normal_at_sphere(sphere, painted_point);
	eye_vec = neg_tuple(ray->direction);
	args = (t_comps *) malloc(sizeof(t_comps));
	args->t = t_value;
	args->object = sphere;
	args->material = sphere->material;
	args->ilum_point = painted_point;
	args->eyev = eye_vec;
	args->normalv = normal;
	args->inside = 0;
	if (dot_product(args->normalv, args->eyev) < 0)
	{
		args->inside = 1;
		args->normalv = neg_tuple(normal);
		free(normal);
	}
	free(painted_direction);
	return (args);
}

void	free_phong_args(t_comps *args)
{
	free(args->ilum_point);
	free(args->normalv);
	free(args->eyev);
	free(args);
}

t_ray	*get_pixel_ray(t_tuple *origin, int i, int j)
{
	t_tuple	*pixel_point;
	t_tuple	*unnormalized_direction;
	t_tuple *direction;
	t_ray	*ray;
	
	pixel_point = create_point(i, j, 0);
	unnormalized_direction = subtract_tuples(pixel_point, origin);
	direction = normalize_tuple(unnormalized_direction);
	ray = create_ray(origin, direction);
	free(pixel_point);
	free(unnormalized_direction);
	return (ray);	
}

int	compute_pixel_color(t_elements *sphere, t_ray *ray, t_elements *light, \
						float t_value)
{
	int				trgb;
	t_comps	*args;
	t_color			*pixel_color;

	args = get_phong_args(sphere, ray, t_value);
	pixel_color = get_lighting_color(light, args);
	if (pixel_color->red > 255)
		pixel_color->red = 255;
	if (pixel_color->green > 255)
		pixel_color->green = 255;
	if (pixel_color->blue > 255)
		pixel_color->blue = 255;
	trgb = get_trgb_from_color(pixel_color);
	free_phong_args(args);
	free(pixel_color);
	return (trgb);
}

void	render_sphere(t_elements *sphere, t_elements *light, \
						t_tuple *origin, t_mlx_data mlx_data)
{
	t_ray *ray;
	int	i;
	int	j;
	t_intersection *aux;

 	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		j = -1;
		while (++j < WINDOW_HEIGHT)
		{
			ray = get_pixel_ray(origin, i, j);
			intersect_object(ray, sphere);
			if (ray->intersections)
			{
				aux = find_hit(ray);
				if (aux)
						mlx_data.image.data[WINDOW_WIDTH * j + i] = \
						compute_pixel_color(sphere, ray, light, aux->t);
			}
			destroy_ray_keeping_origin(ray);
		}
	}
	mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.win_ptr, \
							mlx_data.image.img_ptr, 0, 0);
}
