/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:28:42 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/07 11:49:54 by mgaldino         ###   ########.fr       */
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
	return (new_ray);
}

void	destroy_ray(t_ray *ray)
{
	free(ray->origin);
	free(ray->direction);
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
