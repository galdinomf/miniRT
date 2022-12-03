/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:59:58 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 14:39:54 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrices.h>

void	initiate_matrix_values(t_matrix *matrix)
{
	float	**values;
	int		i;
	int		j;

	values = (float **) malloc(matrix->n_rows * sizeof(float *));
	if (!values)
		return ;
	i = -1;
	while (++i < matrix->n_rows)
	{
		values[i] = (float *) malloc(matrix->n_columns * sizeof(float));
		if (!values[i])
		{
			i = -1;
			while (++i < j)
				free(values[i]);
			free(values);
			matrix->values = NULL;
			return ;
		}
		j = -1;
		while (++j < matrix->n_columns)
			values[i][j] = 0;
	}
	matrix->values = values;
}

t_matrix	*create_matrix(int n_rows, int n_columns)
{
	t_matrix	*new_matrix;

	new_matrix = (t_matrix *) malloc(sizeof(t_matrix));
	new_matrix->n_rows = n_rows;
	new_matrix->n_columns = n_columns;
	initiate_matrix_values(new_matrix);
	return (new_matrix);
}

void	destroy_matrix(t_matrix *matrix)
{
	int	i;

	i = -1;
	while (++i < matrix->n_rows)
			free(matrix->values[i]);
	free(matrix->values);
	free(matrix);
}

void	display_matrix(t_matrix *matrix) //APAGAR!
{
	int	i;
	int	j;

	if (!matrix)
	{
		printf("%p\n", matrix);
		return ;
	}
	i = -1;
	printf("\n");
	while (++i < matrix->n_rows)
	{
		j = -1;
		printf("| ");
		while (++j < matrix->n_columns)
		{
			printf("%f ", matrix->values[i][j]);
		}
		printf("| \n");
	}
}

int	matrices_are_equal(t_matrix *m1, t_matrix *m2)
{
	int	i;
	int	j;

	if ((m1->n_rows != m2->n_rows) || (m1->n_columns != m2->n_columns))
		return (0);
	i = -1;
	while (++i < m1->n_rows)
	{
		j = -1;
		while (++j < m1->n_columns)
		{
			if (!f_equal(m1->values[i][j], m2->values[i][j]))
				return (0);
		}
	}
	return (1);
}