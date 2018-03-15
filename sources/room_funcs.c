/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:47:47 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/15 12:01:43 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		get_index_by_name(t_list *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strequ(((t_room *)rooms->content)->name, name))
			return (((t_room *)rooms->content)->index);
		rooms = rooms->next;
	}
	return (-1);
}

int		get_index_by_status(t_list *rooms, char status)
{
	while (rooms)
	{
		if (((t_room *)rooms->content)->status == status)
			return (((t_room *)rooms->content)->index);
		rooms = rooms->next;
	}
	return (-1);
}

void	set_visited(t_list *rooms, int index)
{
	while (rooms)
	{
		if (((t_room *)rooms->content)->index == index)
			((t_room *)rooms->content)->visited = 1;
		rooms = rooms->next;
	}
}