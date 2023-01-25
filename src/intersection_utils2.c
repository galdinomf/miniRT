/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:05:28 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/24 22:32:11 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	check_cap(t_ray *ray, float t)
{
	float	x;
	float	z;
	float	f;

	x = ray->origin->x + t * ray->direction->x;
	z = ray->origin->z + t * ray->direction->z;
	f = pow(x, 2) + pow(z, 2);
	return ((f < 1) || (f_equal(f, 1)));
}

t_list	*intersect_caps(t_elements *cylinder, t_ray *ray)
{
	float			t;
	t_intersection	*x;
	float			y_limit[2];
	t_list			*xs;
	int				i;

	y_limit[0] = cylinder->point->y + (*cylinder->prop2 / 2);
	y_limit[1] = cylinder->point->y - (*cylinder->prop2 / 2);
	if (f_equal(ray->direction->y, 0))
		return (NULL);
	xs = NULL;
	i = -1;
	while (++i < 2)
	{
		t = (y_limit[i] / *cylinder->prop1 - ray->origin->y) / \
				ray->direction->y;
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

int	is_off_limits(t_ray *ray, t_elements *cylinder, t_list *aux)
{
	float	y_max;
	float	y_min;
	float	y_p;
	float	t;

	y_max = cylinder->point->y + (*cylinder->prop2 / 2);
	y_min = cylinder->point->y - (*cylinder->prop2 / 2);
	t = ((t_intersection *) aux->content)->t;
	y_p = ray->origin->y + t * ray->direction->y;
	if ((y_p >= y_max / *cylinder->prop1) || (y_p <= y_min / *cylinder->prop1))
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
	if (!f_equal(a, 0))
	{
		b = 2 * transf_ray->origin->x * transf_ray->direction->x + \
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
