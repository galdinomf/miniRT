/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:52:54 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/26 01:47:13 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_strlen(char *str);
static char			*ft_alloc_mem(int n);
static int			ft_get_digits_number(int n);

char	*ft_itoa(int n)
{
	int				signal;
	int				i;
	char			*result;
	unsigned int	len_result;

	signal = 1;
	if (n < 0)
		signal = -1;
	result = ft_alloc_mem(n);
	if (result == NULL)
		return (NULL);
	len_result = ft_strlen(result);
	i = 0;
	while ((n != 0) || (i == 0))
	{
		result[len_result - 1 - i] = (n % 10) * signal + '0';
		n /= 10;
		i++;
	}
	if (signal == -1)
		result[0] = '-';
	return (result);
}

static char	*ft_alloc_mem(int n)
{
	char	*result;
	int		n_digits;
	int		i;

	n_digits = ft_get_digits_number(n);
	result = (char *) malloc((n_digits + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < n_digits)
	{
		result[i] = '0';
		i++;
	}
	result[n_digits] = '\0';
	return (result);
}

static int	ft_get_digits_number(int n)
{
	int		signal;
	int		i;
	int		num_digits;

	signal = 0;
	if (n < 0)
		signal = 1;
	num_digits = 0;
	i = n;
	while (i != 0)
	{
		i = i / 10;
		num_digits++;
	}
	if (num_digits == 0)
		num_digits = 1;
	return (num_digits + signal);
}

static unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
