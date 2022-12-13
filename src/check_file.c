#include <miniRT.h>

static void	check_line(char *line);

void	check_file(char *file_name)
{
	char	*line;
	int		fd;

	if (ft_strnrcmp(file_name, ".rt", 3))
		error_exit("Error\nWrong file type\n", 1);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error_exit("Error\nCould not open .rt file\n", 1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 2))
			check_line(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

static void	check_line(char *line)
{
	char **split;
	int	len;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	printf("%s\n", line);
	split = ft_split(line, ' ');
	if (!ft_strcmp(split[0], "A"))
		check_amb_light(split);
	else if(!ft_strcmp(split[0], "C"))
		check_camera(split);
	else if(!ft_strcmp(split[0], "L"))
		check_light(split);
	else if(!ft_strcmp(split[0], "sp"))
		check_sphere(split);
	else if(!ft_strcmp(split[0], "pl"))
		check_plane(split);
	else if(!ft_strcmp(split[0], "cy"))
		check_cylinder(split);
	else
		error_exit("Error\nWrong data in rt file\n", 1);
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
	//free_split((void *)split);
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
		if(!ft_isfloat(split[i]))
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

int	ft_isndvector(char *str)
{
	int		i;
	char	**split;

	split = ft_split(str, ',');
	i = -1;
	while (split[++i])
	{
		if(!(ft_isfloat(split[i]) || ft_atof(split[i]) < 1 || ft_atof(split[i]) > -1))
		{
			free_split((void *)split);
			return (0);
		}
	}
	if (i != 3 || !isnormalized(ft_atof(split[0]), ft_atof(split[1]), ft_atof(split[2])))
	{
			free_split((void *)split);
			return (0);
	}
	free_split((void *)split);
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
		if(!ft_isfloat(split[i]) || ft_atof(split[i]) > 1 || ft_atof(split[i]) < -1)
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

void check_cylinder(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isndvector(str[2]) && ft_isfloat(str[3]) && ft_isfloat(str[4]) &&ft_isrgb(str[5]) &&!str[6]))
		error_exit("Error\nWrong data for sphere\n", 1);
}