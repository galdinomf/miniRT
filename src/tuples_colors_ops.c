/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_colors_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:13:31 by mgaldino          #+#    #+#             */
/*   Updated: 2023/01/17 19:15:05 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

t_color	*create_color(float r, float g, float b)
{
	t_color	*new_color;

	new_color = (t_color *) malloc(sizeof(t_color));
	if (new_color)
	{
		new_color->red = r;
		new_color->green = g;
		new_color->blue = b;
	}
	return (new_color);
}

t_color	*sum_colors(t_color *c1, t_color *c2)
{
	t_color	*new_color;

	new_color = (t_color *) malloc(sizeof(t_color));
	if (new_color)
	{
		new_color->red = c1->red + c2->red;
		new_color->green = c1->green + c2->green;
		new_color->blue = c1->blue + c2->blue;
	}
	return (new_color);
}

t_color	*subtract_colors(t_color *c1, t_color *c2)
{
	t_color	*new_color;

	new_color = (t_color *) malloc(sizeof(t_color));
	if (new_color)
	{
		new_color->red = c1->red - c2->red;
		new_color->green = c1->green - c2->green;
		new_color->blue = c1->blue - c2->blue;
	}
	return (new_color);
}

t_color	*multiply_colors(t_color *c1, t_color *c2)
{
	t_color	*new_color;

	new_color = (t_color *) malloc(sizeof(t_color));
	if (new_color)
	{
		new_color->red = c1->red * c2->red;
		new_color->green = c1->green * c2->green;
		new_color->blue = c1->blue * c2->blue;
	}
	return (new_color);
}

t_color	*multiply_color_by_scalar(t_color *c1, float k)
{
	t_color	*new_color;

	new_color = (t_color *) malloc(sizeof(t_color));
	if (new_color)
	{
		new_color->red = c1->red * k;
		new_color->green = c1->green * k;
		new_color->blue = c1->blue * k;
	}
	return (new_color);
}
