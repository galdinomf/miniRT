/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:05 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 14:23:03 by mgaldino         ###   ########.fr       */
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