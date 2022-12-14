/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rendering_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/05 09:31:46 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main()
{
	t_mlx_data mlx_data;
	minilibx_initialize(&mlx_data);

	//generate_sample_img(&mlx_data);

	///////////// create light //////////////
	t_elements *light = (t_elements *) malloc(sizeof(t_elements));
	light->type = LIGHT;
	light->point = create_point(-10, 10, -10);
	light->color = create_color(1, 1, 1);

/*	DEFAULT MATERIAL
	t_material *m = (t_material *) malloc(sizeof(t_material));
	m->color = create_color(1, 1, 1);
	m->ambient = 0.1;
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->shininess = 200;
*/
	t_material *m1 = (t_material *) malloc(sizeof(t_material));
	m1->color = create_color(1, 0.9, 0.9);
	m1->ambient = 0.1;
	m1->diffuse = 0.9;
	m1->specular = 0;
	m1->shininess = 200;

	t_elements *s1 = (t_elements *) malloc(sizeof(t_elements));
	s1->type = PLANE;
	s1->point = create_point(0,0,0);
	s1->material = m1;
	s1->transformation = get_translation_matrix(0,0,0);

	t_elements *s2 = (t_elements *) malloc(sizeof(t_elements));
	s2->type = PLANE;
	s2->point = create_point(0,0,0);
	s2->material = m1;
	s2->transformation = get_x_rotation_matrix(PI / 2);

	t_material *m5 = (t_material *) malloc(sizeof(t_material));
	m5->color = create_color(1, 0.1, 0.1);
	m5->ambient = 0.1;
	m5->diffuse = 0.9;
	m5->specular = 0;
	m5->shininess = 200;


	t_elements *c1 = (t_elements *) malloc(sizeof(t_elements));
	c1->type = CYLINDER;
	c1->point = create_point(0,1,0);
	c1->prop2 = (float *) malloc (sizeof(float));
	*c1->prop2 = 1.5;
	c1->material = m5;
	t_matrix *trans = get_translation_matrix(2.5,1.2,0);
	t_matrix *z_rot = get_z_rotation_matrix(0 * PI / 4);
	t_matrix *x_rot = get_x_rotation_matrix(1 * PI / 4);
	t_matrix *aux_matrix = multiply_matrices(trans, z_rot);
	c1->transformation = multiply_matrices(aux_matrix, x_rot);
	destroy_matrix(trans);
	destroy_matrix(z_rot);
	destroy_matrix(x_rot);
	destroy_matrix(aux_matrix);
	
/*
	t_elements *s1 = (t_elements *) malloc(sizeof(t_elements));
	s1->type = SPHERE;
	s1->point = create_point(0,0,0);
	s1->material = m1;
	s1->transformation = get_scaling_matrix(10, 0.01, 10);

	t_elements *s2 = (t_elements *) malloc(sizeof(t_elements));
	s2->type = SPHERE;
	s2->point = create_point(0,0,0);
	s2->material = m1;
	t_matrix *trans1 = get_translation_matrix(0,0,5);
	t_matrix *rot1 = get_y_rotation_matrix(-1 * PI / 4);
	t_matrix *rot2 = get_x_rotation_matrix(PI / 2);
	t_matrix *sca1 = get_scaling_matrix(10, 0.01, 10);
	t_matrix *aux_matrix1 = multiply_matrices(trans1, rot1);
	t_matrix *aux_matrix2 = multiply_matrices(aux_matrix1, rot2);
	destroy_matrix(aux_matrix1);	
	s2->transformation =  multiply_matrices(aux_matrix2, sca1);	
	destroy_matrix(aux_matrix2);
	destroy_matrix(trans1);
	destroy_matrix(rot1);
	destroy_matrix(rot2);
	destroy_matrix(sca1);

	t_elements *s3 = (t_elements *) malloc(sizeof(t_elements));
	s3->type = SPHERE;
	s3->point = create_point(0,0,0);
	s3->material = m1;
	trans1 = get_translation_matrix(0,0,5);
	rot1 = get_y_rotation_matrix(PI / 4);
	rot2 = get_x_rotation_matrix(PI / 2);
	sca1 = get_scaling_matrix(10, 0.01, 10);
	aux_matrix1 = multiply_matrices(trans1, rot1);
	aux_matrix2 = multiply_matrices(aux_matrix1, rot2);
	destroy_matrix(aux_matrix1);	
	s3->transformation =  multiply_matrices(aux_matrix2, sca1);
	destroy_matrix(aux_matrix2);
	destroy_matrix(trans1);
	destroy_matrix(rot1);
	destroy_matrix(rot2);
	destroy_matrix(sca1);
*/
	t_material *m2 = (t_material *) malloc(sizeof(t_material));
	m2->color = create_color(0.1, 1, 0.5);
	m2->ambient = 0.1;
	m2->diffuse = 0.7;
	m2->specular = 0.3;
	m2->shininess = 200;

	t_elements *s4 = (t_elements *) malloc(sizeof(t_elements));
	s4->type = SPHERE;
	s4->point = create_point(0,0,0);
	s4->material = m2;
	s4->transformation = get_translation_matrix(-0.5, 1, 0.5);

	t_material *m3 = (t_material *) malloc(sizeof(t_material));
	m3->color = create_color(0.5, 1, 0.1);
	m3->ambient = 0.1;
	m3->diffuse = 0.7;
	m3->specular = 0.3;
	m3->shininess = 200;

	t_elements *s5 = (t_elements *) malloc(sizeof(t_elements));
	s5->type = SPHERE;
	s5->point = create_point(0,0,0);
	s5->material = m3;
	t_matrix *trans2 = get_translation_matrix(1.5,0.5,-0.5);
	t_matrix *sca2 = get_scaling_matrix(0.5, 0.5, 0.5);
	s5->transformation = multiply_matrices(trans2, sca2);
	destroy_matrix(trans2);
	destroy_matrix(sca2);

	t_material *m4 = (t_material *) malloc(sizeof(t_material));
	m4->color = create_color(1, 0.8, 1);
	m4->ambient = 0.1;
	m4->diffuse = 0.7;
	m4->specular = 0.3;
	m4->shininess = 200;

	t_elements *s6 = (t_elements *) malloc(sizeof(t_elements));
	s6->type = SPHERE;
	s6->point = create_point(0,0,0);
	s6->material = m4;
	trans2 = get_translation_matrix(-1.5,0.33,-0.75);
	sca2 = get_scaling_matrix(0.33, 0.33, 0.33);
	s6->transformation = multiply_matrices(trans2, sca2);
	destroy_matrix(trans2);
	destroy_matrix(sca2);
	///////////// create spheres //////////////
	///////////// create data //////////////
	t_data	*world = (t_data *) malloc(sizeof(t_data));
	world->n_elem = 7;
	t_elements **elements = (t_elements **) malloc(world->n_elem * sizeof(t_elements *));
	elements[0] = s2;
	//elements[1] = s2;
	elements[1] = light;
	//elements[3] = s3;
	elements[2] = s4;
	elements[3] = s5;
	elements[4] = s6;
	elements[5] = s1;
	elements[6] = c1;
	//elements[5] = s2;
	world->elem = elements;
	/*
	t_tuple *ray_origin = create_point(0, 0, 0);
	t_tuple *ray_direction = create_vector(0, 0, 1);
	t_ray	*ray = create_ray(ray_origin, ray_direction);

	t_color *my_color = color_at(world, ray);
	printf("my_color = %p\n", my_color);
	printf("my_color = (%f, %f, %f)\n", my_color->red, my_color->green, my_color->blue);

	free(my_color);

	destroy_ray(ray);
	*/
	
	t_camera *camera = create_camera(WINDOW_WIDTH, WINDOW_HEIGHT, PI / 3);
	//t_matrix	*rotation = get_y_rotation_matrix(PI / 4);
	//display_matrix(rotation);
	//t_matrix	*translation = get_translation_matrix(0, -2, 5);
	destroy_matrix(camera->transform);
	//my_camera->transform = multiply_matrices(rotation, translation);


	t_tuple	*from = create_point(1.5,1.5,-8);
	t_tuple	*to = create_point(1.5,1,0);
	t_tuple *up = create_vector(0,1,0);
	camera->transform = view_transform(from, to , up);
	render(camera, world, &mlx_data);
	
	//t_ray *r = ray_for_pixel(my_camera, 100, 50);
	//printf("r->origin = (%f, %f, %f)\n", r->origin->x, r->origin->y, r->origin->z);
	//printf("r->direction = (%f, %f, %f)\n", r->direction->x, r->direction->y, r->direction->z);
	
	//destroy_matrix(rotation);
	//destroy_matrix(translation);
	free(m1->color);
	free(m1);
	free(m2->color);
	free(m2);
	free(m3->color);
	free(m3);
	free(m4->color);
	free(m4);
	free(m5->color);
	free(m5);
	//free(m2->color);
	//free(m2);
	free(c1->point);
	free(c1->prop2);
	destroy_matrix(c1->transformation);
	free(c1);
	free(s1->point);
	destroy_matrix(s1->transformation);
	free(s1);
	free(s2->point);
	destroy_matrix(s2->transformation);
	free(s2);
	/*
	free(s3->point);
	destroy_matrix(s3->transformation);
	free(s3);
	*/
	free(s4->point);
	destroy_matrix(s4->transformation);
	free(s4);
	free(s5->point);
	destroy_matrix(s5->transformation);
	free(s5);
	free(s6->point);
	destroy_matrix(s6->transformation);
	free(s6);
	free(light->point);
	free(light->color);
	free(light);
	free(elements);
	free(world);
	destroy_camera(camera);
	free(from);
	free(to);
	free(up);
	//destroy_ray(r);
	
	
	hook(&mlx_data);
	minilibx_end(&mlx_data);
	
	return (0);
}