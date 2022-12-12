/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:10 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/12 13:55:40 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_data	*file_to_data(char *file_name)
{
	t_data	*data;
	int		fd;


	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error_exit("Error\nCould not open .rt file\n", 1);
	line = get_next_line(fd);
	data = init_file_data();
	while (line)
	{
		if (*line)
			create_elements(line, data);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

t_data	*init_file_data (void)
{
	t_data	*file_data;

	file_data = (t_data *) malloc(sizeof(t_data));
	if (!file_data)
		return (NULL);
	return (file_data);
}

static void	create_elements(char *line, t_data data)
{
	char **split;
	int	len;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	split = ft_split(line, ' ');
	if (!ft_strcmp(split[0], "A"))
		amb_light_to_data(split, data);
	else if(!ft_strcmp(split[0], "C"))
		camera_to_data(split, data);
	else if(!ft_strcmp(split[0], "L"))
		light_to_data(split, data);
	else if(!ft_strcmp(split[0], "sp"))
		sphere_to_data(split, data);
	else if(!ft_strcmp(split[0], "pl"))
		plane_to_data(split, data);
	else if(!ft_strcmp(split[0], "cy"))
		cylinder_to_data(split, data);
	else
		error_exit("Error\nWrong data in rt file\n", 1);
}

void amb_light_to_data(char **str, t_data data)
{
	t_amb_lightning	*amb_light;
	t_color			*rgb;
	char			**split;

	amb_light = malloc(size_of(t_amb_lightning));
	amb_light->ratio = str[1];
	split = ft_split(str[2]);
	amb_light->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split(split);
	data->amb_light = amb_light;
}

void camera_to_data(char **str, t_data data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(size_of(t_elements));
	element->type = str[0];
	split = ft_split(str[1]);
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_vatof(split[2]));
	free_split(split);
	split = ft_split(str[2]);
	element->vector = create_vector(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split(split);
	element->prop1 = (float *) malloc(size_of(float));
	*element->prop1 = ft_atof(str[3]);
	element->prop2 = NULL;
	element->color = NULL;
	data->elem[n_elem] = element;
	data->n_elem++;
}

void ligth_to_data(char **str, t_data data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(size_of(t_elements));
	element->type = str[0];
	split = ft_split(str[1]);
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_vatof(split[2]));
	free_split(split);
	split = ft_split(str[2]);
	element->vector = NULL;
	element->prop1 = (float *) malloc(size_of(float));
	*element->prop1 = ft_atof(str[2]);
	element->prop2 = NULL;
	split = ft_split(str[2]);
	element->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split(split);
	data->elem[n_elem] = element;
	data->n_elem++;
}

void sphere_to_data(char **str, t_data data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(size_of(t_elements));
	element->type = str[0];
	split = ft_split(str[1]);
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_vatof(split[2]));
	free_split(split);
	element->vector = NULL;
	element->prop1 = (float *) malloc(size_of(float));
	*element->prop1 = ft_atof(str[2]);
	element->prop2 = NULL;
	split = ft_split(str[2]);
	element->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split(split);
	data->elem[n_elem] = element;
	data->n_elem++;
}

void plane_to_data(char **str, t_data data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(size_of(t_elements));
	element->type = str[0];
	split = ft_split(str[1]);
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_vatof(split[2]));
	free_split(split);
	split = ft_split(str[2]);
	element->vector = create_vector(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split(split);
	element->prop1 = NULL;
	element->prop2 = NULL;
	split = ft_split(str[3]);
	element->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split(split);
	data->elem[n_elem] = element;
	data->n_elem++;
}

void cylinder_to_data(char **str, t_data data)
{
	t_elements	*element;
	char			**split;

	element = (t_elements *) malloc(size_of(t_elements));
	element->type = str[0];
	split = ft_split(str[1]);
	element->point = create_point(ft_atof(split[0]), ft_atof(split[1]), \
ft_vatof(split[2]));
	free_split(split);
	split = ft_split(str[2]);
	element->vector = create_vector(ft_atof(split[0]), ft_atof(split[1]), \
ft_atof(split[2]));
	free_split(split);
	element->prop1 = (float *) malloc(size_of(float));
	*element->prop1 = ft_atof(str[3]);
	element->prop2 = (float *) malloc(size_of(float));
	*element->prop2 = ft_atof(str[4]);
	split = ft_split(str[5]);
	element->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split(split);
	data->elem[n_elem] = element;
	data->n_elem++;
}

void	printt_data(t_data data)
{
	printf("A	%.2f	%.3f, %.3f, %.3f\n",\
	data->amb_light->ratio,\
	data->amb_light->ratio->color->r\
	data->amb_light->ratio->color->g\
	data->amb_light->ratio->color->b)
}