/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:16:28 by daeidi-h          #+#    #+#             */
/*   Updated: 2023/01/17 19:39:23 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

float	ft_atof(char *str)
{
	char	**split;
	float	nb;
	int		i;

	split = ft_split(str, '.');
	nb = ft_atoi(split[0]);
	i = -1;
	while (split[1] && split[1][++i])
		nb += ((split[1][i] - '0') * pow(10, (i + 1) * -1));
	free_split((void *)split);
	return (nb);
}

int	ft_isfloat(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '-' || str[i] == '+' || ft_isdigit(str[i])))
		return (0);
	i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	if (str[i] != '.')
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	ft_isfloat_range(char *str, float min, float max)
{
	if (ft_isfloat(str) && ft_atof(str) <= max && ft_atof(str) >= min)
		return (1);
	return (0);
}
