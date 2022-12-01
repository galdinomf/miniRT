/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trgb_from_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:41:11 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/01 15:50:08 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	get_trgb_from_color(t_color *color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = (int) color->red;
	g = (int) color->green;
	b = (int) color->blue;
	return (get_trgb_int(t, r, g, b));
}