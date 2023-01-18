/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:12:40 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 18:26:29 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	intersect_world(t_data *world, t_ray *ray)
{
	int	i;

	i = -1;
	while ((++i < world->n_elem) && (world->elem[i]))
	{
		if (world->elem[i]->type > 2)
			intersect_object(ray, world->elem[i]);
	}
}

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
	comps->normalv = get_normal_at_sphere(i->elem, comps->ilum_point); //SUBSTITUIR POR FUNÇÇÃO MAIS GENÉRICA!!
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

static t_elements	*light_off(t_data *data)
{
	t_elements	*element;

	element = (t_elements *) malloc(sizeof(t_elements));
	element->type = LIGHT;
	element->point = create_point(0, 0, 0);
	element->vector = NULL;
	element->prop1 = (float *) malloc(sizeof(float));
	*element->prop1 = data->amb_light->ratio;
	element->prop2 = NULL;
	element->color = create_color(1, 1, 1);
	data->elem[data->n_elem] = element;
	data->n_elem++;
	return (element);
}

t_color	*shade_hit(t_data *world, t_comps *comps)
{
	t_elements	*light;
	int			in_shadow;
	t_color		*color1;
	t_color		*color2;
	t_color		*color3;
	
	color1 = create_color(0, 0, 0);
	int	i = -1;
	light = NULL;
	while (++i < world->n_elem)
	{
		if ((world->elem[i]) && (world->elem[i]->type == LIGHT))
		{
			light = world->elem[i];
			in_shadow = is_shadowed(world, comps->over_point, light);
			color2 = get_lighting_color(light, comps, in_shadow, 0);
			color3 = sum_colors(color1, color2);
			free(color1);
			free(color2);
			color1 = color3;
		}
	}
	if (!light)
	{
		light = light_off(world);
		in_shadow = is_shadowed(world, comps->over_point, light);
		color1 = get_lighting_color(light, comps, in_shadow, 1);
	}
	if (color1->red > 255)
		color1->red = 255;
	if (color1->green > 255)
		color1->green = 255;
	if (color1->blue > 255)
		color1->blue = 255;
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
