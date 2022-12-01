/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:47 by mgaldino          #+#    #+#             */
/*   Updated: 2022/11/30 17:56:14 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main()
{
	t_tuple	*t1 = create_vector(1, 2, 3);
	t_tuple	*t2 = create_vector(4.5, 3.4, -0.5);
	printf("t1 dot t2 = %f\n", dot_product(t1, t2));
	t_tuple *t3 = cross_product(t1, t2);
	printf("t1 cross t2 = (%f, %f, %f)\n", t3->x, t3->y, t3->z);
	free(t1);
	free(t2);
	free(t3);
	return (0);
}