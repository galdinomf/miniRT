/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:34:04 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/05 11:49:48 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	create_material(t_data *data)
{
	int	i;

	i = 0;
	while (data->elem && data->elem[i])
	{
		t_material *m = (t_material *) malloc(sizeof(t_material));
		m->color =  data->elem[i]->color;
		m->ambient = data->amb_light->ratio;
		m->diffuse = 0.9;
		m->specular = 0.9;
		m->shininess = 200;
		data->elem[i]->material = m;
		i++;
	}
}
