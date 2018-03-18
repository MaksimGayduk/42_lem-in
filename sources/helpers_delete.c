/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 09:26:54 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 09:27:18 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_room(void *room, size_t content_size)
{
	if (!room)
		return ;
	ft_strdel(&(((t_room *)room)->name));
	free(room);
	content_size = 0;
}

void	delete_path(void *content, size_t content_size)
{
	if (!content)
		return ;
	free(content);
	content_size = 0;
}

void	delete_pathways(t_list **head)
{
	t_list *temp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		if (temp->content)
			ft_lst_erase((t_list *)temp->content);
		temp->content_size = 0;
		free(temp);
	}
}