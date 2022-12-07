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
		if (*line)
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

	split = ft_split(str, ',');
	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j] && split[i][j] != '\0')
		{
		printf("%d\n", split[i][j]);
			if (!ft_isdigit(split[i][j]))
				return (0);
		}
		if (ft_atoi(split[i]) > 255 || i > 2)
			return (0);

	}
	return (1);
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
			return (0);
	}
	if (i != 2)
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
		if(!ft_isfloat(split[i]) || ft_atof(split[i]) > 1 || ft_atof(split[i]) < -1)
			return (0);
	}
	if (i != 2)
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
		if(!ft_isfloat(split[i]) || ft_atof(split[i]) > 1 || ft_atof(split[i]) < -1)
			return (0);
	}
	if (i != 2)
		return (0);
	return (1);
}

void check_cylinder(char **str)
{
	if (!(ft_iscoords(str[1]) && ft_isndvector(str[2]) && ft_isfloat(str[3]) && ft_isfloat(str[4]) &&ft_isrgb(str[5]) &&!str[6]))
		error_exit("Error\nWrong data for sphere\n", 1);
}