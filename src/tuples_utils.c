/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:47:06 by mgaldino          #+#    #+#             */
/*   Updated: 2022/11/30 17:43:24 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

t_tuple	*create_point(float x, float y, float z)
{
	t_tuple	*new_point;

	new_point = (t_tuple *) malloc(sizeof(t_tuple));
	if (new_point)
	{
		new_point->x = x;
		new_point->y = y;
		new_point->z = z;
		new_point->w = 1;
	}
	return (new_point);
}

t_tuple	*create_vector(float x, float y, float z)
{
	t_tuple	*new_vector;

	new_vector = (t_tuple *) malloc(sizeof(t_tuple));
	if (new_vector)
	{
		new_vector->x = x;
		new_vector->y = y;
		new_vector->z = z;
		new_vector->w = 0;
	}
	return (new_vector);
}

int	is_point(t_tuple *tuple)
{
	return (f_equal(tuple->w, 1));
}

int	is_vector(t_tuple *tuple)
{
	return (f_equal(tuple->w, 0));
}

int	tuples_equal(t_tuple *t1, t_tuple *t2)
{
	if ((!f_equal(t1->x, t2->x)) || (!f_equal(t1->y, t2->y)) || \
		(!f_equal(t1->z, t2->z)) || (!f_equal(t1->w, t2->w)))
		return (0);
	return (1);
}