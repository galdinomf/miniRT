/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lighting_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:38:58 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/23 14:32:43 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
/*computes the resulting color from the Phong reflection model*/

t_color	*get_specular_contribution(t_elements *light, t_tuple *lightv, \
									t_comps *args)
{
	t_tuple	*neg_lightv;
	t_tuple	*reflectv;
	float	reflect_dot_eye;
	float	factor;
	t_color	*specular;
	
	neg_lightv = neg_tuple(lightv);
	reflectv = get_reflected_vector(neg_lightv, args->normalv);
	reflect_dot_eye = dot_product(reflectv, args->eyev);
	if (reflect_dot_eye <= 0)
		specular = create_color(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, args->object->material->shininess);
		specular = multiply_color_by_scalar(light->color, (args->object->material->specular * factor));
	}
	free(neg_lightv);
	free(reflectv);
	return(specular);
}

t_tuple	*get_direction_to_light_source(t_elements *light, t_comps *args)
{
	t_tuple	*unnorm_lightv;
	t_tuple	*lightv;

	unnorm_lightv = subtract_tuples(light->point, args->ilum_point);
	lightv = normalize_tuple(unnorm_lightv);
	free(unnorm_lightv);
	return (lightv);
}

t_color	*get_final_color_and_destroy_contributions(t_color **contributions)
{
	t_color	*aux;
	t_color	*result;

	aux = sum_colors(contributions[0], contributions[1]);
	result = sum_colors(aux, contributions[2]);
	free(aux);
	aux = result;
	result = multiply_color_by_scalar(aux, 255); //MULTIPLICAR POR 255!!!
	free(aux);

	free(contributions[0]);
	free(contributions[1]);
	free(contributions[2]);
	return (result);
}

t_color	*get_lighting_color(t_elements *light, t_comps *args)
{
	t_color	*effective_color;
	t_tuple	*lightv;
	float	light_dot_normal;
	t_color	*contributions[3]; // 0 - ambient; 1 - diffuse; 2 - specular; 3 - aux

	effective_color = multiply_colors(args->object->material->color, light->color);
	lightv = get_direction_to_light_source(light, args);
	contributions[0] = multiply_color_by_scalar(effective_color, args->object->material->ambient);
	light_dot_normal = dot_product(lightv, args->normalv);
	if (light_dot_normal < 0)
	{
		contributions[1] = create_color(0, 0, 0);
		contributions[2] = create_color(0, 0, 0);
	}
	else
	{
		contributions[1] = multiply_color_by_scalar(effective_color, (args->object->material->diffuse * light_dot_normal));
		contributions[2] = get_specular_contribution(light, lightv, args);
	}
	free(effective_color);
	free(lightv);
	return (get_final_color_and_destroy_contributions(contributions));
}
