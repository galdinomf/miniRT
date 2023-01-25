/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:12:40 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/25 06:02:35 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_comps	*prepare_computations(t_intersection *i, t_ray *r)
{
	t_comps	*comps;
	t_tuple	*aux_tuple;

	comps = (t_comps *) malloc(sizeof(t_comps));
	comps->t = i->t;
	comps->object = i->elem;
	aux_tuple = multiply_tuple_by_scalar(r->direction, i->t);
	comps->ilum_point = sum_tuples(r->origin, aux_tuple);
	free(aux_tuple);
	comps->eyev = neg_tuple(r->direction);
	comps->normalv = get_normal(i->elem, comps->ilum_point);
	comps->inside = 0;
	if (dot_product(comps->normalv, comps->eyev) < 0)
	{
		comps->inside = 1;
		aux_tuple = comps->normalv;
		comps->normalv = neg_tuple(comps->normalv);
		free(aux_tuple);
	}
	aux_tuple = multiply_tuple_by_scalar(comps->normalv, EPSILON);
	comps->over_point = sum_tuples(comps->ilum_point, aux_tuple);
	free(aux_tuple);
	return (comps);
}

static t_color	*light_off(t_data *data, t_comps *comps)
{
	t_elements	*element;
	int			in_shadow;
	t_color		*color1;

	element = (t_elements *) malloc(sizeof(t_elements));
	element->type = LIGHT;
	element->point = create_point(0, 0, 0);
	element->vector = NULL;
	element->prop1 = (float *) malloc(sizeof(float));
	*element->prop1 = data->amb_light->ratio;
	element->prop2 = NULL;
	element->color = create_color(1, 1, 1);
	data->elem[data->n_elem] = element;
	in_shadow = is_shadowed(data, comps->over_point, element);
	color1 = get_lighting_color(element, comps, in_shadow, 1);
	free_elem(element);
	return (color1);
}

t_color	*accumulate_color(t_data *world, t_comps *comps, \
							t_elements *light, t_color *color1)
{
	t_color		*color2;
	t_color		*color3;
	int			in_shadow;

	in_shadow = is_shadowed(world, comps->over_point, light);
	color2 = get_lighting_color(light, comps, in_shadow, 0);
	color3 = sum_colors(color1, color2);
	free(color1);
	free(color2);
	return (color3);
}

t_color	*shade_hit(t_data *world, t_comps *comps)
{
	t_elements	*light;
	t_color		*color1;
	int			i;

	i = -1;
	color1 = create_color(0, 0, 0);
	light = NULL;
	while (++i < world->n_elem)
	{
		if ((world->elem[i]) && (world->elem[i]->type == LIGHT))
		{
			light = world->elem[i];
			color1 = accumulate_color(world, comps, light, color1);
		}
	}
	if (!light)
	{
		color1 = light_off(world, comps);
	}
	adjust_color_overflow(color1);
	return (color1);
}

t_color	*color_at(t_data *world, t_ray *ray)
{
	t_intersection	*hit;
	t_comps			*comps;
	t_color			*result;

	intersect_world(world, ray);
	hit = find_hit(ray);
	if (!hit)
		return (create_color(0, 0, 0));
	comps = prepare_computations(hit, ray);
	result = shade_hit(world, comps);
	free(comps->ilum_point);
	free(comps->eyev);
	free(comps->normalv);
	free(comps->over_point);
	free(comps);
	return (result);
}
