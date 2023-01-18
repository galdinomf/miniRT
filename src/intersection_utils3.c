/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:10:08 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/18 10:11:35 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_intersection	*find_hit(t_ray *ray)
{
	t_list			*aux;
	float			smallest_t;
	t_intersection	*result;

	result = NULL;
	aux = ray->intersections;
	while ((aux) && (((t_intersection *) aux->content)->t < 0))
		aux = aux->next;
	if (aux)
	{
		smallest_t = ((t_intersection *) aux->content)->t;
		result = ((t_intersection *) aux->content);
		aux = aux->next;
	}
	while (aux)
	{
		if ((((t_intersection *) aux->content)->t >= 0) && \
			(((t_intersection *) aux->content)->t < smallest_t))
		{
			smallest_t = ((t_intersection *) aux->content)->t;
			result = ((t_intersection *) aux->content);
		}
		aux = aux->next;
	}
	return (result);
}
