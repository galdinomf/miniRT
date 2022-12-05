/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:45:49 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/05 15:08:35 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrices.h>

t_matrix	*get_translation_matrix(float x, float y, float z)
{
	t_matrix	*new_matrix;

	new_matrix = get_identity_matrix(4);
	if (!new_matrix)
		return (NULL);
	new_matrix->values[0][3] = x;
	new_matrix->values[1][3] = y;
	new_matrix->values[2][3] = z;
	return (new_matrix);
}

t_matrix	*get_scaling_matrix(float x, float y, float z)
{
	t_matrix	*new_matrix;

	new_matrix = get_identity_matrix(4);
	if (!new_matrix)
		return (NULL);
	new_matrix->values[0][0] = x;
	new_matrix->values[1][1] = y;
	new_matrix->values[2][2] = z;
	return (new_matrix);
}

t_matrix	*get_x_rotation_matrix(float radians)
{
	t_matrix	*new_matrix;

	new_matrix = get_identity_matrix(4);
	if (!new_matrix)
		return (NULL);
	new_matrix->values[1][1] = cos(radians);
	new_matrix->values[1][2] = (-1) * sin(radians);
	new_matrix->values[2][1] = sin(radians);
	new_matrix->values[2][2] = cos(radians);
	return (new_matrix);
}

t_matrix	*get_y_rotation_matrix(float radians)
{
	t_matrix	*new_matrix;

	new_matrix = get_identity_matrix(4);
	if (!new_matrix)
		return (NULL);
	new_matrix->values[0][0] = cos(radians);
	new_matrix->values[0][3] = sin(radians);
	new_matrix->values[2][0] = (-1) * sin(radians);
	new_matrix->values[2][2] = cos(radians);
	return (new_matrix);
}

t_matrix	*get_z_rotation_matrix(float radians)
{
	t_matrix	*new_matrix;

	new_matrix = get_identity_matrix(4);
	if (!new_matrix)
		return (NULL);
	new_matrix->values[0][0] = cos(radians);
	new_matrix->values[0][1] = (-1) * sin(radians);
	new_matrix->values[1][0] = sin(radians);
	new_matrix->values[1][1] = cos(radians);
	return (new_matrix);
}

t_matrix	*get_shearing_matrix(float x_y, float x_z, \
								float y_x, float y_z, \
								float z_x, float z_y)
// i += i_j * j
{
	t_matrix	*new_matrix;

	new_matrix = get_identity_matrix(4);
	if (!new_matrix)
		return (NULL);
	new_matrix->values[0][1] = x_y;
	new_matrix->values[0][2] = x_z;
	new_matrix->values[1][0] = y_x;
	new_matrix->values[1][2] = y_z;
	new_matrix->values[2][0] = z_x;
	new_matrix->values[2][1] = z_y;
	return (new_matrix);
}
