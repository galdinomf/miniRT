/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:59:58 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 12:49:04 by mgaldino         ###   ########.fr       */
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