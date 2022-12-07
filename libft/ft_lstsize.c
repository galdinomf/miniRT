/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:56:45 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/27 03:13:59 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*next_address;

	if (!lst)
		return (0);
	i = 1;
	next_address = lst->next;
	while (next_address != NULL)
	{
		i++;
		next_address = next_address->next;
	}
	return (i);
}
