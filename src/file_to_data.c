/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:10 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/12 19:17:18 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_data	*init_file_data (void)
{
	t_data	*file_data;

	file_data = (t_data *) malloc(sizeof(t_data));
	if (!file_data)
		return (NULL);
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
	return (data);
}

void	amb_light_to_data(char **str, t_data *data)
{
	t_amb_lightning	*amb_light;
	char			**split;

	amb_light = (t_amb_lightning *)malloc(sizeof(t_amb_lightning));
	amb_light->ratio = ft_atof(str[1]);
	split = ft_split(str[2], ' ');
	amb_light->color = create_color(ft_atof(split[0])/255, \
ft_atof(split[1])/255, ft_atof(split[2])/255);
	free_split((void *)split);
	data->amb_light = amb_light;
}

void	print_data(t_data *data)
{
	printf("A	%.2f	%.3f, %.3f, %.3f\n",\
	data->amb_light->ratio,\
	data->amb_light->color->red, \
	data->amb_light->color->green, \
	data->amb_light->color->blue);
}