/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflected_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:38:35 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 18:18:21 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
/*get the resulting vector of the reflection of an
 incoming vector around a given normal vector*/

t_tuple	*get_reflected_vector(t_tuple *vector, t_tuple *normal)
{
	t_tuple	*aux;
	t_tuple	*result;

	aux = multiply_tuple_by_scalar(normal, (2 * dot_product(vector, normal)));
	result = subtract_tuples(vector, aux);
	free(aux);
	return (result);
}
