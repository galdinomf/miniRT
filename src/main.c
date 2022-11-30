/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/11/30 16:50:13 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main()
{
	t_tuple	*t1 = create_point(1, 2, 3);
	t_tuple	*t2 = create_vector(4.5, 3.4, -0.5);
	t_tuple *t3 = divide_tuple_by_scalar(t2, -2.5);
	printf("t3 = (%f, %f, %f)\n", t3->x, t3->y, t3->z);
	free(t1);
	free(t2);
	free(t3);
	return (0);
}