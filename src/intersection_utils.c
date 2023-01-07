/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:49:30 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/06 16:47:01 by daeidi-h         ###   ########.fr       */
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

int		check_cap(t_ray *ray, float t)
{
	float	x;
	float	z;
	float	f;

	x = ray->origin->x + t * ray->direction->x;
	z = ray->origin->z + t * ray->direction->z;
	f = pow(x, 2) + pow(z, 2);
	return ((f < 1) || (f_equal(f,1)));
}

t_list	*intersect_caps(t_elements *cylinder, t_ray *ray)
{
	float	t;
	t_intersection	*x;
	float	y_limit[2];
	t_list	*xs;
	int	i;

	y_limit[0] = cylinder->point->y + (*cylinder->prop2 / 2);
	y_limit[1] = cylinder->point->y - (*cylinder->prop2 / 2);
	if (f_equal(ray->direction->y, 0))
		return NULL;
	xs = NULL;
	i = -1;
	while (++i < 2)
	{
		t = (y_limit[i] - ray->origin->y) / ray->direction->y;
		if (check_cap(ray, t))
		{
			x = (t_intersection *) malloc(sizeof(t_intersection));
			x->t = t;
			x->elem = cylinder;
			ft_lstadd_back(&xs, ft_lstnew(x));
		}		
	}
	return (xs);
}

int		is_off_limits(t_ray *ray, t_elements *cylinder, t_list *aux)
{
	float	y_max;
	float	y_min;
	float	y_p;
	float	t;
	
	y_max = cylinder->point->y + (*cylinder->prop2 / 2);
	y_min = cylinder->point->y - (*cylinder->prop2 / 2);
	t = ((t_intersection *) aux->content)->t;
	y_p = ray->origin->y + t * ray->direction->y;
	if ((y_p >= y_max) || (y_p <= y_min))
		return (1);
	return (0);
}

void	cut_intersections_out_of_bounds(t_ray *ray, t_elements *cylinder, \
										t_list **intersections)
{
	t_list	*aux;
	t_list	*aux2;

	aux = *intersections;
	if (!aux)
		return ;
	aux2 = aux->next;
	if (is_off_limits(ray, cylinder, aux2))
	{
		ft_lstdelone(aux2, free);
		aux->next = NULL;
	}
	if (is_off_limits(ray, cylinder, aux))
	{
		*intersections = aux->next;
		ft_lstdelone(aux, free);
	}
}

void	intersect_cylinder(t_ray *ray, t_elements *cylinder)
{
	t_ray		*transf_ray;
	float		a;
	float		b;
	float		c;
	t_list		*intersections;

	transf_ray = transform_element(ray, cylinder);
	a = pow(transf_ray->direction->x, 2) + pow(transf_ray->direction->z, 2);
	if	(!f_equal(a, 0))
	{
		b = 2 * transf_ray->origin->x * transf_ray->direction->x +\
			2 * transf_ray->origin->z * transf_ray->direction->z;
		c = pow(transf_ray->origin->x, 2) + pow(transf_ray->origin->z, 2) - 1;
		intersections = get_intersections(a, b, c, cylinder);
		cut_intersections_out_of_bounds(transf_ray, cylinder, &intersections);
		ft_lstadd_back(&ray->intersections, intersections);		
	}
	intersections = intersect_caps(cylinder, transf_ray);
	ft_lstadd_back(&ray->intersections, intersections);
	destroy_ray(transf_ray);
}

void	intersect_sphere(t_ray *ray, t_elements *sphere)
{
	float		a;
	float		b;
	float		c;
	t_tuple		*sphere_to_ray;
	t_ray		*transf_ray;

	transf_ray = transform_element(ray, sphere);
	sphere_to_ray = subtract_tuples(transf_ray->origin, sphere->point);
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
	t_ray		*transf_ray;

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

t_intersection	*find_hit(t_ray *ray)
{
	t_list	*aux;
	float	smallest_t;
	t_intersection	*result;

	result = NULL;
	aux = ray->intersections;
	while ((aux) && (((t_intersection *) aux->content)->t < 0))
		aux = aux->next;
	if (aux)
	{
		smallest_t = ((t_intersection *) aux->content)->t;
		result = ((t_intersection *) aux->content);
		aux = aux->next;
	}
	while (aux)
	{
		if ((((t_intersection *) aux->content)->t >= 0) && \
			(((t_intersection *) aux->content)->t < smallest_t))
			{
				smallest_t = ((t_intersection *) aux->content)->t;
				result = ((t_intersection *) aux->content);
			}
		aux = aux->next;
	}
	return (result);
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
