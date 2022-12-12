/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:24:46 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/12 19:26:42 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	camera_to_data(char **str, t_data *data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(sizeof(t_elements));
	element->type = 2;
	split = ft_split(str[1], ' ');
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split((void *)split);
	split = ft_split(str[2], ' ');
	element->vector = create_vector(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split((void *)split);
	element->prop1 = (float *) malloc(sizeof(float));
	*element->prop1 = ft_atof(str[3]);
	element->prop2 = NULL;
	element->color = NULL;
	data->elem[data->n_elem] = element;
	data->n_elem++;
}

void	light_to_data(char **str, t_data *data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(sizeof(t_elements));
	element->type = 3;
	split = ft_split(str[1], ' ');
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split((void *)split);
	split = ft_split(str[2], ' ');
	element->vector = NULL;
	element->prop1 = (float *) malloc(sizeof(float));
	*element->prop1 = ft_atof(str[2]);
	element->prop2 = NULL;
	split = ft_split(str[2], ' ');
	element->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split((void *)split);
	data->elem[data->n_elem] = element;
	data->n_elem++;
}

void	sphere_to_data(char **str, t_data *data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(sizeof(t_elements));
	element->type = 4;
	split = ft_split(str[1], ' ');
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split((void *)split);
	element->vector = NULL;
	element->prop1 = (float *) malloc(sizeof(float));
	*element->prop1 = ft_atof(str[2]);
	element->prop2 = NULL;
	split = ft_split(str[2], ' ');
	element->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split((void *)split);
	data->elem[data->n_elem] = element;
	data->n_elem++;
}

void	plane_to_data(char **str, t_data *data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(sizeof(t_elements));
	element->type = 5;
	split = ft_split(str[1], ' ');
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split((void *)split);
	split = ft_split(str[2], ' ');
	element->vector = create_vector(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split((void *)split);
	element->prop1 = NULL;
	element->prop2 = NULL;
	split = ft_split(str[3], ' ');
	element->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split((void *)split);
	data->elem[data->n_elem] = element;
	data->n_elem++;
}

void	cylinder_to_data(char **str, t_data *data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(sizeof(t_elements));
	element->type = 6;
	split = ft_split(str[1], ' ');
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split((void *)split);
	split = ft_split(str[2], ' ');
	element->vector = create_vector(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split((void *)split);
	element->prop1 = (float *) malloc(sizeof(float));
	*element->prop1 = ft_atof(str[3]);
	element->prop2 = (float *) malloc(sizeof(float));
	*element->prop2 = ft_atof(str[4]);
	split = ft_split(str[5], ' ');
	element->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split((void *)split);
	data->elem[data->n_elem] = element;
	data->n_elem++;
}
