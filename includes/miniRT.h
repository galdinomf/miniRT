/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:18:54 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 22:17:32 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <tuples.h>
# include <minilibx.h>
# include <matrices.h>
# include <unistd.h>			// write(), close(), access(), fork(), pipe()
# include <fcntl.h>				// open()
# include "../libft/libft.h"

//-----STRUCTURES

# define EPSILON 0.01
# define AMB_LIGHTNING 1
# define CAMERA 2
# define LIGHT 3
# define SPHERE 4
# define PLANE 5
# define CYLINDER 6

typedef struct s_camera
{
	int			hsize;
	int			vsize;
	float		field_of_view;
	t_matrix	*transform;
	float		half_width;
	float		half_height;
	float		pixel_size;
}	t_camera;

typedef struct s_material
{
	t_color	*color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef struct s_elements
{
	int			type;
	t_tuple		*point;
	t_tuple		*vector;
	float		*prop1;
	float		*prop2;
	t_color		*color;
	t_matrix	*transformation;
	t_material	*material;
}	t_elements;

typedef struct s_comps
{
	t_elements	*object;
	float		t;
	t_material	*material;
	int			inside;
	t_tuple		*ilum_point;
	t_tuple		*eyev;
	t_tuple		*normalv;
	t_tuple		*over_point;
}	t_comps;

typedef struct s_ray
{
	t_tuple	*origin;
	t_tuple	*direction;
	t_list	*intersections;
}	t_ray;

typedef struct s_intersection
{
	float		t;
	t_elements	*elem;
}	t_intersection;

typedef struct s_amb_lightning
{
	float		ratio;
	t_color		*color;
}	t_amb_lightning;

typedef struct s_data
{
	int				n_elem;
	t_amb_lightning	*amb_light;
	t_elements		*cam;
	t_elements		**elem;
}	t_data;

//////////////////// CHECK FILE RT ////////////////////
void			check_file(char *file_name);
int				check_amb_light(char **str);
int				check_camera(char **str);
int				check_light(char **str);
int				check_sphere(char **str);
int				check_plane(char **str);
int				check_cylinder(char **str);
void			error_exit(const char *s, int i);
float			ft_atof(char *str);
int				ft_isfloat(char *str);
int				ft_isfloat_range(char *str, float min, float max);
int				ft_isrgb(char *str);
int				ft_iscoords(char *str);
int				ft_isndvector(char *str);
int				isnormalized(float x, float y, float z);

/////////////FILE TO DATA ////////////////////////

t_data			*file_to_data(char *file_name);
void			amb_light_to_data(char **str, t_data *data);
void			print_data(t_data *data);
void			camera_to_data(char **str, t_data *data);
void			light_to_data(char **str, t_data *data);
void			sphere_to_data(char **str, t_data *data);
void			plane_to_data(char **str, t_data *data);
void			cylinder_to_data(char **str, t_data *data);
void			create_material_and_set_transformation(t_data *data);

//////TRANSFORMATIONS///

void			trasnform_elements(t_data *data);
void			transform_camera(t_camera *camera, t_data *data);

///////FREE////
void			free_split(void **ptr);
void			free_ptr(void **ptr);
void			free_data(t_data *data);
//------MACROS

void			hook(t_mlx_data *mlx_data);
int				keypress(int keysym, t_mlx_data *mlx_data);
t_tuple			*multiply_matrix_by_tuple(t_matrix *matrix, t_tuple *tuple);

t_ray			*create_ray(t_tuple *origin, t_tuple *direction);
void			destroy_ray(t_ray *ray);
void			destroy_ray_keeping_origin(t_ray *ray);
t_tuple			*ray_position(t_ray *ray, float t);

void			intersect_sphere(t_ray *ray, t_elements *sphere);
t_intersection	*find_hit(t_ray *ray);
void			intersect_object(t_ray *ray, t_elements *object);
void			intersect_world(t_data *world, t_ray *ray);

t_color			*color_at(t_data *world, t_ray *ray);

//t_tuple	*convert_matrix_to_tuple(t_matrix *matrix);
t_ray			*transform_ray(t_ray *ray, t_matrix *transf_matrix);

t_tuple			*get_normal_at_sphere(t_elements *sphere, t_tuple *world_point);
t_tuple			*get_reflected_vector(t_tuple *vector, t_tuple *normal);

t_color			*get_lighting_color(t_elements	*light, t_comps *args, \
									int in_shadow, int no_light);
void			render_sphere(t_elements *sphere, t_elements *light, \
						t_tuple *origin, t_mlx_data mlx_data);

t_matrix		*view_transform(t_tuple *from, t_tuple *to, t_tuple *up);

t_camera		*create_camera(int hsize, int vsize, float field_of_view);
void			destroy_camera(t_camera *camera);
void			compute_pixel_size(t_camera *camera);
t_ray			*ray_for_pixel(t_camera *camera, float px, float py);

void			render(t_camera *camera, t_data *world, t_mlx_data *mlx_data);
int				is_shadowed(t_data *world, t_tuple *point, t_elements *light);

void			intersect_cylinder(t_ray *ray, t_elements *cylinder);

int				round_float(float f);

#endif