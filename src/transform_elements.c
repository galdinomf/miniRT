/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:30:38 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/24 22:37:20 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	rotations(t_elements	*elem);
static void	transform_elem(t_elements *elem);

void	trasnform_elements(t_data *data)
{
	int	i;

	i = -1;
	while (data->elem && data->elem[++i])
	{
		if (data->elem[i]->type > 3)
		{
			transform_elem(data->elem[i]);
		}
	}
}

static void	transform_elem(t_elements *elem)
{
	t_matrix	*aux1;
	t_matrix	*aux2;

	aux1 = NULL;
	aux2 = NULL;
	elem->transformation = get_translation_matrix(elem->point->x, \
												elem->point->y, elem->point->z);
	if (elem->prop1)
		aux1 = get_scaling_matrix(*elem->prop1, *elem->prop1, *elem->prop1);
	if (aux1)
	{
		aux2 = elem->transformation;
		elem->transformation = multiply_matrices(aux2, aux1);
		destroy_matrix(aux1);
		destroy_matrix(aux2);
	}
	if (elem->vector)
		rotations(elem);
}

static void	rotations(t_elements	*elem)
{
	t_matrix	*aux1;
	t_matrix	*aux2;

	aux1 = elem->transformation;
	aux2 = get_x_rotation_matrix(atan2(elem->vector->z, elem->vector->y));
	elem->transformation = multiply_matrices(aux1, aux2);
	destroy_matrix(aux1);
	destroy_matrix(aux2);
	aux1 = elem->transformation;
	aux2 = get_y_rotation_matrix(atan2(elem->vector->z, elem->vector->x));
	elem->transformation = multiply_matrices(aux1, aux2);
	destroy_matrix(aux1);
	destroy_matrix(aux2);
	aux1 = elem->transformation;
	aux2 = get_z_rotation_matrix(atan2(elem->vector->x, elem->vector->y));
	elem->transformation = multiply_matrices(aux1, aux2);
	destroy_matrix(aux1);
	destroy_matrix(aux2);
}
