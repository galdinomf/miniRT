/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:49:30 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/10 19:57:43 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_list	*get_intersections(float a, float b, float c, t_elements *sphere)
{
	t_intersection	*new_intersection1;
	t_intersection	*new_intersection2;
	t_list			*intersections;
	float			discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (NULL);
	new_intersection1 = (t_intersection *) malloc(sizeof(t_intersection));
	if (!new_intersection1)
		return (NULL);
	new_intersection2 = (t_intersection *) malloc(sizeof(t_intersection));
	if (!new_intersection2)
		return (NULL);
	new_intersection1->t = ((-1) * b - sqrt(discriminant)) / (2 * a);
	new_intersection1->elem = sphere;
	new_intersection2->t = ((-1) * b + sqrt(discriminant)) / (2 * a);
	new_intersection2->elem = sphere;
	intersections = ft_lstnew(new_intersection1);
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection2));
	return (intersections);
}

void	intersect_sphere(t_ray *ray, t_elements *sphere) // MUDAR SEGUNDO ARGUMENTO PARA ENDEREÇO DA ESFERA!!!
{
	float		a;
	float		b;
	float		c;
	t_tuple		*sphere_to_ray;
	t_list		*intersections;

	sphere_to_ray = subtract_tuples(ray->origin, sphere->point);
	a = dot_product(ray->direction, ray->direction);
	b = 2 * dot_product(ray->direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	intersections = get_intersections(a, b, c, sphere);
	ray->intersections = intersections;
	free(sphere_to_ray);
}

t_intersection	*get_hit(t_ray *ray)
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