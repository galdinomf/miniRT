/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_material_and_set_transformation.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:34:04 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/18 10:27:06 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	create_material_and_set_transformation(t_data *data)
{
	int			i;
	t_material	*m;

	i = 0;
	while (data->elem && data->elem[i])
	{
		m = (t_material *) malloc(sizeof(t_material));
		m->color = data->elem[i]->color;
		m->ambient = data->amb_light->ratio;
		m->diffuse = 0.9;
		m->specular = 0.9;
		m->shininess = 200;
		data->elem[i]->material = m;
		data->elem[i]->transformation = NULL;
		i++;
	}
}
