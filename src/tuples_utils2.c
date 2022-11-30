/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:28:31 by mgaldino          #+#    #+#             */
/*   Updated: 2022/11/30 16:48:43 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

t_tuple	*sum_tuples(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*result;

	result = (t_tuple *) malloc(sizeof(t_tuple));
	result->x = t1->x + t2->x;
	result->y = t1->y + t2->y;
	result->z = t1->z + t2->z;
	result->w = t1->w + t2->w;
	return (result);
}

t_tuple	*subtract_tuples(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*result;

	result = (t_tuple *) malloc(sizeof(t_tuple));
	result->x = t1->x - t2->x;
	result->y = t1->y - t2->y;
	result->z = t1->z - t2->z;
	result->w = t1->w - t2->w;
	return (result);
}

t_tuple	*neg_tuple(t_tuple *t1)
{
	t_tuple	*result;

	result = (t_tuple *) malloc(sizeof(t_tuple));
	result->x = t1->x * -1;
	result->y = t1->y * -1;
	result->z = t1->z * -1;
	result->w = t1->w * -1;
	return (result);
}

t_tuple	*multiply_tuple_by_scalar(t_tuple *t1, float k)
{
	t_tuple	*result;

	result = (t_tuple *) malloc(sizeof(t_tuple));
	result->x = t1->x * k;
	result->y = t1->y * k;
	result->z = t1->z * k;
	result->w = t1->w * k;
	return (result);
}

t_tuple	*divide_tuple_by_scalar(t_tuple *t1, float k)
{
	t_tuple	*result;

	result = (t_tuple *) malloc(sizeof(t_tuple));
	result->x = t1->x / k;
	result->y = t1->y / k;
	result->z = t1->z / k;
	result->w = t1->w / k;
	return (result);
}
