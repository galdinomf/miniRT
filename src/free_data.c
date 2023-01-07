/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:12:04 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/05 12:18:14 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	free_elem(t_elements *elem)
{
	if (elem->point)	
		free_ptr((void *)&elem->point);
	if (elem->vector)	
		free_ptr((void *)&elem->vector);
	if (elem->prop1)
		free_ptr((void *)&elem->prop1);
	if (elem->prop2)
		free_ptr((void *)&elem->prop2);
	if (elem->color)	
		free_ptr((void *)&elem->color);
	if (elem->material)	
		free_ptr((void *)&elem->material);
	if (elem->transformation)
		destroy_matrix(elem->transformation);
	free_ptr((void *) &elem);
}

void	free_data(t_data *data)
{
	int	i;
	if (data->amb_light)
	{
		free_ptr((void *)&data->amb_light->color);
		free_ptr((void *)&data->amb_light);
	}
	i = -1;
	while (data->elem && data->elem[++i])
		free_elem(data->elem[i]);
	free_ptr((void *)&data->elem);
	free_ptr((void *)&data);
}
