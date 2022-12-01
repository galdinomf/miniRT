/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:11 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/01 15:55:53 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include <stdlib.h>
# include <math.h>


typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

t_tuple	*create_point(float x, float y, float z);
t_tuple	*create_vector(float x, float y, float z);
int		is_point(t_tuple *tuple);
int		is_vector(t_tuple *tuple);
int		tuples_equal(t_tuple *t1, t_tuple *t2);
t_tuple	*sum_tuples(t_tuple *t1, t_tuple *t2);
t_tuple	*subtract_tuples(t_tuple *t1, t_tuple *t2);
t_tuple	*neg_tuple(t_tuple *t1);
t_tuple	*multiply_tuple_by_scalar(t_tuple *t1, float k);
t_tuple	*divide_tuple_by_scalar(t_tuple *t1, float k);
float	tuple_magnitude(t_tuple *tuple);
t_tuple	*normalize_tuple(t_tuple *tuple);
float	dot_product(t_tuple *t1, t_tuple *t2);
t_tuple	*cross_product(t_tuple *t1, t_tuple *t2);

int	f_equal(float f1, float f2);

/////////////////////// COLORS ///////////////////////
typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
}	t_color;

t_color *create_color(float r, float g, float b);
t_color	*sum_colors(t_color *c1, t_color *c2);
t_color	*subtract_colors(t_color *c1, t_color *c2);
t_color	*multiply_colors(t_color *c1, t_color *c2);
t_color	*multiply_color_by_scalar(t_color *c1, float k);
int	get_trgb_from_color(t_color *color);

#endif