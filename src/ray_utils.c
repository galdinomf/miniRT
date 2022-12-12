/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:28:42 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/12 09:41:28 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_ray	*create_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*new_ray;

	new_ray = (t_ray *) malloc(sizeof(t_ray));
	if ((!new_ray) || (!is_point(origin)) || (!is_vector(direction)))
		return (NULL);
	new_ray->origin = origin;
	new_ray->direction = direction;
	new_ray->intersections = NULL;
	return (new_ray);
}

void	destroy_ray(t_ray *ray)
{
	free(ray->origin);
	free(ray->direction);
	ft_lstclear(&ray->intersections, free);
	free(ray);
	ray = NULL;
}

t_tuple	*ray_position(t_ray *ray, float t)
{
	t_tuple	*aux_tuple;
	t_tuple	*result;

	aux_tuple = multiply_tuple_by_scalar(ray->direction, t);
	result = sum_tuples(ray->origin, aux_tuple);
	free(aux_tuple);
	return (result);
}

t_ray	*transform_ray(t_ray *ray, t_matrix *transf_matrix)
{
	t_ray		*resulting_ray;
	t_matrix	*aux1;
	t_matrix	*aux2;

	aux1 = multiply_matrix_by_tuple(transf_matrix, ray->origin);
	aux2 = multiply_matrix_by_tuple(transf_matrix, ray->direction);
	resulting_ray = create_ray(convert_matrix_to_tuple(aux1), \
								convert_matrix_to_tuple(aux2));
	destroy_matrix(aux1);
	destroy_matrix(aux2);
	return (resulting_ray);
}
