/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:26:56 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/20 13:56:13 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

#define EPSILON 0.001

void	intersect_plane(t_ray *ray, t_elements *plane) // MUDAR SEGUNDO ARGUMENTO PARA ENDEREÇO DA ESFERA!!!
{
	t_intersection	*new_intersection;
	t_ray			*transf_ray;

	transf_ray = transform_element(ray, plane);
	if (abs(transf_ray->origin->y < EPSILON))
		return ;
	else 
	{
		new_intersection = (t_intersection *) malloc(sizeof(t_intersection));
		new_intersection->t = transf_ray->origin->y*-1 / transf_ray->direction->y;
		new_intersection->elem = plane;
		ft_lstadd_back(&ray->intersections, ft_lstnew(new_intersection));
	}
	destroy_ray(transf_ray);
}

void	intersect_elements(t_ray *ray, t_elements **elem)
{
	int	i;
	i = -1;
	while (elem[++i])
	{
		if (elem[i]->type == 4)
			intersect_sphere(ray, elem[i]);
		else if (elem[i]->type == 5)
			intersect_plane(ray, elem[i]);
	}

}