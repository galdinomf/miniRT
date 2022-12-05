/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:32:33 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/05 13:33:31 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrices.h>
// A PARTIR DAQUI, TUDO NECESSÁRIO PARA INVERTER MATRIZES

float	determinant_2d_matrix(t_matrix *matrix)
{
	return (matrix->values[0][0] * matrix->values[1][1] - \
	matrix->values[0][1] * matrix->values[1][0]);
}

float	cofactor(t_matrix *matrix, int row, int col)
{
	float	minor;
	t_matrix	*aux;

	aux = get_submatrix(matrix, row, col);
	minor = determinant_nd_matrix(aux);
	destroy_matrix(aux);
	return (pow(-1, (row + col)) * minor);
}
float	determinant_nd_matrix(t_matrix *matrix)
{
	float	det;
	int		j;

	if (matrix->n_columns == 2)
		return (determinant_2d_matrix(matrix));
	det = 0;
	j = -1;
	while (++j < matrix->n_columns)
		det += matrix->values[0][j] * cofactor(matrix, 0, j);
	return (det);
}

int	matrix_is_invertible(t_matrix *matrix)
{
	return (!f_equal(determinant_nd_matrix(matrix), 0));
}

t_matrix	*get_inverse_matrix(t_matrix *matrix)
{
	t_matrix	*inverse_matrix;
	int			i;
	int			j;
	float		c;

	if (!matrix_is_invertible(matrix))
		return (NULL);
	inverse_matrix = create_matrix(matrix->n_rows, matrix->n_columns);
	if (!inverse_matrix)
		return (NULL);
	i = -1;
	while (++i < matrix->n_rows)
	{
		j = -1;
		while (++j < matrix->n_columns)
		{
			c = cofactor(matrix, i, j);
			inverse_matrix->values[j][i] = c / determinant_nd_matrix(matrix);
		}
	}
	return (inverse_matrix);
}
