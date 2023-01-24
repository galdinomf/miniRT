/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:57:51 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/24 11:29:57 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# ifndef PI
#  define PI 3.141592654
# endif

typedef struct s_matrix
{
	int		n_rows;
	int		n_columns;
	float	**values;
}	t_matrix;
//////////////////// MATRIX BASICS ////////////////////
t_matrix	*create_matrix(int n_rows, int n_columns);
void		destroy_matrix(t_matrix *matrix);
void		display_matrix(t_matrix *matrix); //APAGAR

//////////////////// MATRIX OPERATIONS ////////////////////
int			matrices_are_equal(t_matrix *m1, t_matrix *m2);
t_matrix	*multiply_matrices(t_matrix *m1, t_matrix *m2);
t_matrix	*get_transposed_matrix(t_matrix *matrix);
t_matrix	*get_identity_matrix(int n);
float		determinant_2d_matrix(t_matrix *matrix);
t_matrix	*get_submatrix(t_matrix *matrix, int rmved_row, int rmved_column);
//float		minor_of_3d_square_matrix(t_matrix *matrix, int row, int col);
float		cofactor(t_matrix *matrix, int row, int col);
//float	determinant_3d_square_matrix(t_matrix *matrix);
float		determinant_nd_matrix(t_matrix *matrix);
int			matrix_is_invertible(t_matrix *matrix);
t_matrix	*get_inverse_matrix(t_matrix *matrix);

//////////////////// MATRIX TRANSFORMATIONS ////////////////////
t_matrix	*get_translation_matrix(float x, float y, float z);
t_matrix	*get_scaling_matrix(float x, float y, float z);
t_matrix	*get_x_rotation_matrix(float radians);
t_matrix	*get_y_rotation_matrix(float radians);
t_matrix	*get_z_rotation_matrix(float radians);			
int			f_equal(float f1, float f2);
#endif