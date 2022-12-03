/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:18:54 by mgaldino          #+#    #+#             */
/*   Updated: 2022/12/03 13:09:30 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <tuples.h>
# include <minilibx.h>
# include <matrices.h>

void	hook(t_mlx_data *mlx_data);
int	keypress(int keysym, t_mlx_data *mlx_data);


#endif