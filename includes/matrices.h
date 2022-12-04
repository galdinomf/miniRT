/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:57:51 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 21:26:27 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_matrix
{
	int		n_rows;
	int		n_columns;
	float	**values;
}	t_matrix;

t_matrix	*create_matrix(int n_rows, int n_columns);
void		destroy_matrix(t_matrix *matrix);
void		display_matrix(t_matrix *matrix); //APAGAR
int			matrices_are_equal(t_matrix *m1, t_matrix *m2);
t_matrix	*multiply_matrices(t_matrix *m1, t_matrix *m2);
t_matrix	*get_transposed_matrix(t_matrix *matrix);
t_matrix	*get_identity_matrix(int n);
float		determinant_2d_matrix(t_matrix *matrix);
t_matrix	*get_submatrix(t_matrix *matrix, int rmved_row, int rmved_column);
//float		minor_of_3d_square_matrix(t_matrix *matrix, int row, int col);
float	cofactor(t_matrix *matrix, int row, int col);
//float	determinant_3d_square_matrix(t_matrix *matrix);
float	determinant_nd_matrix(t_matrix *matrix);
int	matrix_is_invertible(t_matrix *matrix);
t_matrix	*get_inverse_matrix(t_matrix *matrix);
int			f_equal(float f1, float f2);
#endif