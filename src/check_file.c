/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:32:44 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/24 12:10:01 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	check_line(char *line);

void	check_file(char *file_name)
{
	char	*line;
	int		fd;
	int		error;

	if (ft_strnrcmp(file_name, ".rt", 3))
		error_exit("Error\nWrong file type\n", 1);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error_exit("Error\nCould not open .rt file\n", 1);
	line = get_next_line(fd, 0);
	while (line)
	{
		if (ft_strncmp(line, "\n", 2))
			error = check_line(line);
		free(line);
		if (error)
		{
			line = get_next_line(fd, 1);
			error_exit("Error\nWrong structure in file\n", error);
		}
		line = get_next_line(fd, 0);
	}
	close(fd);
	free(line);
}

static int	check_line(char *line)
{
	char	**split;
	int		len;
	int		result;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	result = 0;
	split = ft_split(line, ' ');
	if (!ft_strcmp(split[0], "A"))
		result = check_amb_light(split);
	else if (!ft_strcmp(split[0], "C"))
		result = check_camera(split);
	else if (!ft_strcmp(split[0], "L"))
		result = check_light(split);
	else if (!ft_strcmp(split[0], "sp"))
		result = check_sphere(split);
	else if (!ft_strcmp(split[0], "pl"))
		result = check_plane(split);
	else if (!ft_strcmp(split[0], "cy"))
		result = check_cylinder(split);
	else
		result = 7;
	free_split((void *)split);
	return (result);
}

int	ft_isrgb(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		ok;

	split = ft_split(str, ',');
	i = -1;
	ok = 1;
	while (split[++i] && ok == 1)
	{
		j = -1;
		while (split[i][++j] && split[i][j] != '\0')
		{
			if (!ft_isdigit(split[i][j]))
				ok = 0;
		}
		if (ft_atoi(split[i]) > 255 || i > 2)
			ok = 0;
	}
	free_split((void *)split);
	return (ok);
}

int	ft_iscoords(char *str)
{
	int		i;
	char	**split;

	split = ft_split(str, ',');
	i = -1;
	while (split[++i])
	{
		if (!ft_isfloat(split[i]))
		{
			free_split((void *)split);
			return (0);
		}
	}
	free_split((void *)split);
	if (i != 3)
		return (0);
	return (1);
}

int	ft_isfov(char *str)
{
	int		i;
	char	**split;

	split = ft_split(str, ',');
	i = -1;
	while (split[++i])
	{
		if (!ft_isfloat(split[i]) || \
			ft_atof(split[i]) > 1 || ft_atof(split[i]) < -1)
		{
			free_split((void *)split);
			return (0);
		}
	}
	free_split((void *)split);
	if (i != 2)
		return (0);
	return (1);
}
