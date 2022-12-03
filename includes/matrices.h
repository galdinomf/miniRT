/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:57:51 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 14:21:13 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <stdlib.h>
# include <stdio.h>

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

int			f_equal(float f1, float f2);
#endif