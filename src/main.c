/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/07 12:33:08 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char **argv)
{
	t_data		*data;
	t_camera	*camera;
	t_mlx_data	mlx_data;

	if (argc != 2)
		error_exit("Error\nArgs invalid\n", 1);
	check_file(argv[1]);
	data = file_to_data(argv[1]);
	create_material(data);
	trasnform_elements(data);
	print_data(data);
	minilibx_initialize(&mlx_data);
	camera = create_camera(WINDOW_WIDTH, WINDOW_HEIGHT, \
*data->cam->prop1 * PI / 180);
	transform_camera(camera, data);
	render(camera, data, &mlx_data);
	free_data(data);
	destroy_camera(camera);
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	return (0);
}
