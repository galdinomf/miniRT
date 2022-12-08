/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:18:54 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/07 12:27:40 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <tuples.h>
# include <minilibx.h>
# include <matrices.h>

typedef struct s_ray
{
	t_tuple	*origin;
	t_tuple	*direction;
}	t_ray;

typedef struct s_intersection
{
	int		count;
	float	*xs;
}	t_intersection;

void		hook(t_mlx_data *mlx_data);
int			keypress(int keysym, t_mlx_data *mlx_data);
t_matrix	*multiply_matrix_by_tuple(t_matrix *matrix, t_tuple *tuple);


t_ray	*create_ray(t_tuple *origin, t_tuple *direction);
void	destroy_ray(t_ray *ray);
t_tuple	*ray_position(t_ray *ray, float t);

t_intersection	*intersect_sphere(t_ray *ray, t_tuple *sp_center); // MUDAR SEGUNDO ARGUMENTO PARA ENDEREÇO DA ESFERA!!!
void	destroy_intersection(t_intersection *intersecion);
#endif