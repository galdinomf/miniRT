/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:49:30 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/07 20:33:53 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_intersection	*get_intersection(float a, float b, float c)
{
	t_intersection	*new_intersection;
	float			discriminant;

	new_intersection = (t_intersection *) malloc(sizeof(t_intersection));
	if (!new_intersection)
		return (NULL);
	new_intersection->count = 0;
	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		new_intersection->xs = NULL;
	else
	{
		new_intersection->count += 2;
		new_intersection->xs = (float *) malloc(2 * sizeof(float));
		new_intersection->xs[0] = ((-1) * b - sqrt(discriminant)) / (2 * a);
		new_intersection->xs[1] = ((-1) * b + sqrt(discriminant)) / (2 * a);
	}
	return (new_intersection);
}

void	destroy_intersection(t_intersection *intersecion)
{
	free(intersecion->xs);
	free(intersecion);
}

t_intersection	*intersect_sphere(t_ray *ray, t_tuple *sp_center) // MUDAR SEGUNDO ARGUMENTO PARA ENDEREÇO DA ESFERA!!!
{
	float			a;
	float			b;
	float			c;
	t_tuple			*sphere_to_ray;
	t_intersection	*new_intersection;

	sphere_to_ray = subtract_tuples(ray->origin, sp_center);
	a = dot_product(ray->direction, ray->direction);
	b = 2 * dot_product(ray->direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	new_intersection = get_intersection(a, b, c);
	return (new_intersection);
}


