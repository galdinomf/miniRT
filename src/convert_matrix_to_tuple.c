/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_matrix_to_tuple.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:40:08 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/10 12:45:17 by mgaldino         ###   ########.fr       */
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