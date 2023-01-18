/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:31:24 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 18:32:46 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
/*
t_tuple	*get_vector_from_point_to_light(t_elements *light, t_tuple *point)
{
	t_tuple *v;

	v = subtract_tuples(light->point, point);
}
*/
int	is_shadowed(t_data *world, t_tuple *point, t_elements *light)
{
	t_tuple			*v;
	t_ray			*r;
	t_intersection	*hit;
	int				result;
	t_tuple			*direction;

	result = 0;
	v = subtract_tuples(light->point, point);
	direction = normalize_tuple(v);
	r = create_ray(point, direction);
	intersect_world(world, r);
	hit = find_hit(r);
	if (hit && (hit->t < tuple_magnitude(v)))
		result = 1;
	destroy_ray_keeping_origin(r);
	free(v);
	return (result);
}
