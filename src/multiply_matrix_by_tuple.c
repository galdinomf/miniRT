/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_by_tuple.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:56:12 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/14 10:49:13 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_tuple	*convert_matrix_to_tuple(t_matrix *matrix)
{
	t_tuple	*new_tuple;
	float	x;
	float	y;
	float	z;
	float	w;

	if ((matrix->n_rows != 4) || (matrix->n_columns != 1) || (!matrix->values))
		return (NULL);
	x = matrix->values[0][0];
	y = matrix->values[1][0];
	z = matrix->values[2][0];
	w = matrix->values[3][0];
	new_tuple = create_point(x, y, z);
	new_tuple->w = w;
	return (new_tuple);
}

t_tuple	*multiply_matrix_by_tuple(t_matrix *matrix, t_tuple *tuple)
{
	t_matrix	*tuple_converted;
	t_matrix	*result;
	t_tuple		*resulting_tuple;

	tuple_converted = create_matrix(4, 1);
	tuple_converted->values[0][0] = tuple->x;
	tuple_converted->values[1][0] = tuple->y;
	tuple_converted->values[2][0] = tuple->z;
	tuple_converted->values[3][0] = tuple->w;
	result = multiply_matrices(matrix, tuple_converted);
	destroy_matrix(tuple_converted);
	resulting_tuple = convert_matrix_to_tuple(result);
	return (resulting_tuple);
}
