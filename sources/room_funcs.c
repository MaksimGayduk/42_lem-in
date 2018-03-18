/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:47:47 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 16:55:36 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int		get_index_by_status(t_room *room_arr, int room_num, char status)
{
	int i;

	i = 0;
	while (i < room_num)
	{
		if (room_arr[i].status == status)
			return (room_arr[i].index);
		i++;
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
