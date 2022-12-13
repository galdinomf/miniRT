/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:10 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/13 19:30:43 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	count_elem(char *file_name)
{
	char	*line;
	int		fd;
	int		count;

	if (ft_strnrcmp(file_name, ".rt", 3))
		error_exit("Error\nWrong file type\n", 1);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error_exit("Error\nCould not open .rt file\n", 1);
	line = get_next_line(fd);
	count = -1;
	while (line)
	{
		if (ft_strncmp(line, "\n", 2))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return(count);
}

static t_data	*init_file_data (int qtt_elem)
{
	t_data	*file_data;
	file_data = (t_data *) malloc(sizeof(t_data));
	if (!file_data)
		return (NULL);
	file_data->elem = malloc(sizeof(t_elements) * qtt_elem);
	file_data->n_elem = 0;
	return (file_data);
}

static void	create_elements(char *line, t_data *data)
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

t_data	*file_to_data(char *file_name)
{
	t_data	*data;
	int		fd;
	char	*line;
	int		qtt_elem;

	qtt_elem = count_elem(file_name);
	printf("n elem = %d\n", qtt_elem);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error_exit("Error\nCould not open .rt file\n", 1);
	line = get_next_line(fd);
	data = init_file_data(qtt_elem);
	while (line)
	{
		if (ft_strncmp(line, "\n", 2))
			create_elements(line, data);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (data);
}

void	amb_light_to_data(char **str, t_data *data)
{
	t_amb_lightning	*amb_light;
	char			**split;

	amb_light = (t_amb_lightning *)malloc(sizeof(t_amb_lightning));
	amb_light->ratio = ft_atof(str[1]);
	split = ft_split(str[2], ',');
	amb_light->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split((void *)split);
	data->amb_light = amb_light;
}

void	print_data(t_data *data)
{
	int i;
	printf("A	%.2f	%.3f, %.3f, %.3f\n",\
	data->amb_light->ratio,\
	data->amb_light->color->red, \
	data->amb_light->color->green, \
	data->amb_light->color->blue);
	i = -1;
	while(data->elem[++i])
		printf("%d\n",	data->elem[i]->type);
}
