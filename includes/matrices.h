/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:57:51 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 12:50:40 by mgaldino         ###   ########.fr       */
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
void	destroy_matrix(t_matrix *matrix);
void	display_matrix(t_matrix *matrix); //APAGAR

#endif