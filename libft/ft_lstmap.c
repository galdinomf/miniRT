/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaldino <mgaldino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:55:01 by mgaldino          #+#    #+#             */
/*   Updated: 2022/04/27 03:13:50 by mgaldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list;
	t_list	*node_ptr;
	t_list	*new_node;

	if (lst == NULL)
		return (NULL);
	node_ptr = lst;
	result_list = ft_lstnew((*f)(node_ptr->content));
	if (!result_list)
		return (0);
	node_ptr = node_ptr->next;
	while (node_ptr)
	{
		new_node = ft_lstnew((*f)(node_ptr->content));
		if (!new_node)
			ft_lstclear(&result_list, (*del));
		ft_lstadd_back(&result_list, new_node);
		node_ptr = node_ptr->next;
	}
	return (result_list);
}
