/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:22:04 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/12 10:28:18 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	round_float(float f)
{
	double	int_part;
	float	frac_part;

	frac_part = modf(f, &int_part);
	if (frac_part >= 0.5)
		return (ceil(int_part));
	else
		return (floor(int_part));
}