/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:05 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 19:16:50 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrices.h>

t_matrix	*multiply_matrices(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*new_matrix;
	int			i;
	int			j;
	int			k;

	if (m1->n_columns != m2->n_rows)
		return (NULL);
	new_matrix = create_matrix(m1->n_rows, m2->n_columns);
	if ((!new_matrix) || (!new_matrix->values))
		return (NULL);
	i = -1;
	while (++i < m1->n_rows)
	{
		j = -1;
		while (++j < m2->n_columns)
		{
			k = -1;
			while (++k < m1->n_columns)
				new_matrix->values[i][j] += m1->values[i][k] * m2->values[k][j];
		}
	}
	return (new_matrix);
}

t_matrix	*get_transposed_matrix(t_matrix *matrix)
{
	t_matrix	*new_matrix;
	int			i;
	int			j;

	if (matrix->n_columns != matrix->n_rows)
		return (NULL);
	new_matrix = create_matrix(matrix->n_rows, matrix->n_columns);
	if (new_matrix == NULL)
		return (NULL);
	i = -1;
	while (++i < matrix->n_rows)
	{
		j = -1;
		while (++j < matrix->n_columns)
			new_matrix->values[i][j] = matrix->values[j][i];
	}
	return (new_matrix);
}

t_matrix	*get_identity_matrix(int n)
{
	t_matrix	*new_matrix;
	int			i;

	if (n < 1)
		return (NULL);
	new_matrix = create_matrix(n, n);
	if (!new_matrix)
		return (NULL);
	printf("new_matrix->values = %p\n", new_matrix->values);
	i = -1;
	while (++i < n)
		new_matrix->values[i][i] = 1;
	return (new_matrix);
}

// A PARTIR DAQUI, TUDO NECESSÁRIO PARA INVERTER MATRIZES

float	determinant_2d_square_matrix(t_matrix *matrix)
{
	return (matrix->values[0][0] * matrix->values[1][1] - \
	matrix->values[0][1] * matrix->values[1][0]);
}

t_matrix	*get_submatrix(t_matrix *matrix, int rmved_row, int rmved_column)
{
	t_matrix	*new_matrix;
	int			i;
	int			j;

	new_matrix = create_matrix(matrix->n_rows - 1, matrix->n_columns - 1);
	if (!new_matrix)
		return (NULL);
	i = -1;
	while (++i < new_matrix->n_rows)
	{
		j = -1;
		while (++j < new_matrix->n_columns)
		{
			new_matrix->values[i][j] = matrix->values[i + (i >= rmved_row)][j + (j >= rmved_column)];
		}
	}
	return (new_matrix);
}
/*
float	minor_of_3d_square_matrix(t_matrix *matrix, int row, int col)
{
	t_matrix	*submatrix;
	float		minor;

	submatrix = get_submatrix(matrix, row, col);
	minor = determinant_2d_square_matrix(submatrix);
	destroy_matrix(submatrix);
	return (minor);
}
*/
float	cofactor(t_matrix *matrix, int row, int col)
{
	float	minor;
	t_matrix	*aux;

	//minor = minor_of_3d_square_matrix(matrix, row, col);
		aux = get_submatrix(matrix, row, col);
	minor = determinant_nd_square_matrix(aux);
		destroy_matrix(aux);
	return (pow(-1, (row + col)) * minor);
}
/*
float	determinant_3d_square_matrix(t_matrix *matrix)
{
	float	cof1;
	float	cof2;
	float	cof3;

	cof1 = matrix->values[0][0] * cofactor(matrix, 0, 0);
	cof2 = matrix->values[0][1] * cofactor(matrix, 0, 1);
	cof3 = matrix->values[0][2] * cofactor(matrix, 0, 2);
	return (cof1 + cof2 + cof3);
}
*/
float	determinant_nd_square_matrix(t_matrix *matrix)
{
	float	det;
	int		j;
//	t_matrix	*aux;

	if (matrix->n_columns == 2)
		return (determinant_2d_square_matrix(matrix));
	det = 0;
	j = -1;
	while (++j < matrix->n_columns)
	{
		//aux = get_submatrix(matrix, 0, j);
		det += matrix->values[0][j] * cofactor(matrix, 0, j);
		//destroy_matrix(aux);
	}
	return (det);
}