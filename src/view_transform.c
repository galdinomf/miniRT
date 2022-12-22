/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:14:18 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/22 12:15:39 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_tuple	*get_forward(t_tuple *from, t_tuple *to)
{
	t_tuple	*unnormalized_forward;
	t_tuple	*forward;

	unnormalized_forward = subtract_tuples(to, from);
	forward = normalize_tuple(unnormalized_forward);
	free(unnormalized_forward);
	return (forward);
}

t_matrix	*get_orientation_matrix(t_tuple *left, t_tuple *true_up, t_tuple *forward)
{
	t_matrix	*orientation;

	orientation = get_identity_matrix(4);
	orientation->values[0][0] = left->x;
	orientation->values[0][1] = left->y;
	orientation->values[0][2] = left->z;
	orientation->values[1][0] = true_up->x;
	orientation->values[1][1] = true_up->y;
	orientation->values[1][2] = true_up->z;
	orientation->values[2][0] = forward->x * -1;
	orientation->values[2][1] = forward->y * -1;
	orientation->values[2][2] = forward->z * -1;
	return (orientation);
}

t_matrix	*final_orientation_matrix(t_tuple *from, t_tuple *true_up, \
										t_tuple *forward, t_tuple *left)
{
	t_matrix	*orientation;
	t_matrix	*translation;
	t_matrix	*orientation_with_translation;
		
	orientation = get_orientation_matrix(left, true_up, forward);
	translation = get_translation_matrix(from->x * -1, from->y * -1, from->z * -1);
	orientation_with_translation = multiply_matrices(orientation, translation);
	destroy_matrix(orientation);
	destroy_matrix(translation);
	return (orientation_with_translation);
}

t_matrix	*view_transform(t_tuple *from, t_tuple *to, t_tuple *up)
{
	t_tuple	*forward;
	t_tuple	*norm_up;
	t_tuple	*left;
	t_tuple	*true_up;
	t_matrix	*result;

	forward = get_forward(from, to);
	norm_up = normalize_tuple(up);
	left = cross_product(forward, norm_up);
	true_up = cross_product(left, forward);
	result = final_orientation_matrix(from, true_up, forward, left);
	
	free(forward);
	free(norm_up);
	free(left);
	free(true_up);
	return (result);
}
