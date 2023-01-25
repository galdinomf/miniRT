/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:49:30 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/24 22:35:22 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_ray	*transform_element(t_ray *ray, t_elements *element)
{
	t_matrix	*inv_transf_matrix;
	t_ray		*transf_ray;

	inv_transf_matrix = get_inverse_matrix(element->transformation);
	transf_ray = transform_ray(ray, inv_transf_matrix);
	destroy_matrix(inv_transf_matrix);
	return (transf_ray);
}

t_list	*get_intersections(float a, float b, float c, t_elements *sphere)
{
	t_intersection	*new_intersection1;
	t_intersection	*new_intersection2;
	t_list			*intersections;
	float			discriminant;
	float			sqrt_discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (NULL);
	new_intersection1 = (t_intersection *) malloc(sizeof(t_intersection));
	if (!new_intersection1)
		return (NULL);
	new_intersection2 = (t_intersection *) malloc(sizeof(t_intersection));
	if (!new_intersection2)
		return (NULL);
	sqrt_discriminant = sqrt(discriminant);
	new_intersection1->t = ((-1) * b - sqrt_discriminant) / (2 * a);
	new_intersection1->elem = sphere;
	new_intersection2->t = ((-1) * b + sqrt_discriminant) / (2 * a);
	new_intersection2->elem = sphere;
	intersections = ft_lstnew(new_intersection1);
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection2));
	return (intersections);
}

void	intersect_sphere(t_ray *ray, t_elements *sphere)
{
	float		a;
	float		b;
	float		c;
	t_tuple		*sphere_to_ray;
	t_ray		*transf_ray;

	transf_ray = transform_element(ray, sphere);
	sphere_to_ray = create_vector(transf_ray->origin->x, transf_ray->origin->y, \
									transf_ray->origin->z);
	a = dot_product(transf_ray->direction, transf_ray->direction);
	b = 2 * dot_product(transf_ray->direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	ft_lstadd_back(&ray->intersections, get_intersections(a, b, c, sphere));
	destroy_ray(transf_ray);
	free(sphere_to_ray);
}

void	intersect_plane(t_ray *ray, t_elements *plane)
{
	t_intersection	*intersection;
	t_ray			*transf_ray;

	transf_ray = transform_element(ray, plane);
	if (fabs(transf_ray->direction->y) < EPSILON)
	{
		destroy_ray(transf_ray);
		return ;
	}
	intersection = (t_intersection *) malloc(sizeof(t_intersection));
	intersection->t = (-1 * transf_ray->origin->y) / transf_ray->direction->y;
	intersection->elem = plane;
	ft_lstadd_back(&ray->intersections, ft_lstnew(intersection));
	destroy_ray(transf_ray);
}

void	intersect_object(t_ray *ray, t_elements *object)
{
	if (object->type == SPHERE)
		intersect_sphere(ray, object);
	if (object->type == PLANE)
		intersect_plane(ray, object);
	if (object->type == CYLINDER)
		intersect_cylinder(ray, object);
}
