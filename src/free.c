/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:13:29 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/12/12 12:19:23 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include<minishell.h>

void	free_ptr(void **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_split(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free_ptr((void *) &ptr[i++]);
	free_ptr((void *) &ptr);
}
