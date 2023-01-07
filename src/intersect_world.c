/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:12:40 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/06 14:04:22 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	intersect_world(t_data *world, t_ray *ray)
{
	int	i;

	i = -1;
	while ((++i < world->n_elem) && (world->elem[i]))
	{
		if ( world->elem[i]->type > 2)
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

t_color	*shade_hit(t_data *world, t_comps *comps)
{
	t_elements	*light;
	int			in_shadow;

	// ISTO TERÁ QUE SER MUDADO! A FUNÇÃO CONSIDERA QUE EXISTE
	// UMA LUZ PERTENCENTE À CLASSE WORLD! (LUZ AMBIENTE?)
	// FOI FEITO ASSIM PARA MANTER O FORMATO SUGERIDO NO LIVRO
	int	i = -1;
	while (++i < world->n_elem)
	{
		if ((world->elem[i]) && (world->elem[i]->type == LIGHT))
			light = world->elem[i];
	}
	in_shadow = is_shadowed(world, comps->over_point);
	return (get_lighting_color(light, comps, in_shadow));
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