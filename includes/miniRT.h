/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:18:54 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/14 10:49:44 by mgaldino         ###   ########.fr       */
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


//------MACROS

#define AMB_LIGHTNING 1
#define CAMERA 2
#define LIGHT 3
#define SPHERE 4
#define PLANE 5
#define CYLINDER 6

//-----STRUCTURES


typedef struct s_elements
{
	int			type;
	t_tuple		*point;
	t_tuple		*vector;
	float		*prop1;
	float		*prop2;
	t_color		*color;
	t_matrix	*transformation;
}	t_elements;

typedef struct s_amb_lightning
{
	float		ratio;
	t_color		*color;
}	t_amb_lightning;

typedef struct s_data
{
	t_amb_lightning	*amb_light;
	t_elements		*elem;
}	t_data;

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

void			hook(t_mlx_data *mlx_data);
int				keypress(int keysym, t_mlx_data *mlx_data);
t_tuple	*multiply_matrix_by_tuple(t_matrix *matrix, t_tuple *tuple);


t_ray	*create_ray(t_tuple *origin, t_tuple *direction);
void	destroy_ray(t_ray *ray);
t_tuple	*ray_position(t_ray *ray, float t);

void	intersect_sphere(t_ray *ray, t_elements *sphere); 
t_intersection	*get_hit(t_ray *ray);

//t_tuple	*convert_matrix_to_tuple(t_matrix *matrix);
t_ray	*transform_ray(t_ray *ray, t_matrix *transf_matrix);

//////////////////// CHECK FILE RT ////////////////////
void		check_file(char *file_name);
void		check_amb_light(char **str);
void 		check_camera(char **str);
void 		check_light(char **str);
void 		check_sphere(char **str);
void 		check_plane(char **str);
void 		check_cylinder(char **str);
void		error_exit(const char *s, int i);
float		ft_atof(char *str);
int 		ft_isfloat(char *str);
int 		ft_isfloat_range(char *str, float min, float max);
int			ft_isrgb(char *str);
int			ft_iscoords(char *str);
int			ft_isndvector(char *str);
int 		isnormalized(float x, float y, float z);

int	round_float(float f);
#endif