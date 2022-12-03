/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutiply_matrix_by_tuple.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:56:12 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 15:05:37 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_matrix	*multiply_matrix_by_tuple(t_matrix *matrix, t_tuple *tuple)
{
	t_matrix	*tuple_converted;
	t_matrix	*result;

	tuple_converted = create_matrix(4, 1);
	tuple_converted->values[0][0] = tuple->x;
	tuple_converted->values[1][0] = tuple->y;
	tuple_converted->values[2][0] = tuple->z;
	tuple_converted->values[3][0] = tuple->w;
	result = multiply_matrices(matrix, tuple_converted);
	return (result);
}
