/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/18 12:32:28 by mgaldino         ###   ########.fr       */
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
	create_material_and_set_transformation(data);
	trasnform_elements(data);
	minilibx_initialize(&mlx_data);
	camera = create_camera(WINDOW_WIDTH, WINDOW_HEIGHT, \
		*data->cam->prop1 * PI / 180);
	transform_camera(camera, data);
	printf("Rendering...\n");
	render(camera, data, &mlx_data);
	printf("\nDone!\n");
	free_data(data);
	destroy_camera(camera);
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	return (0);
}
