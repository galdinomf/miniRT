/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:08:37 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/18 11:09:02 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	intersect_world(t_data *world, t_ray *ray)
{
	int	i;

	i = -1;
	while ((++i < world->n_elem) && (world->elem[i]))
	{
		if (world->elem[i]->type > 2)
			intersect_object(ray, world->elem[i]);
	}
}
