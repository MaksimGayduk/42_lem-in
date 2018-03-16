/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:16:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/15 13:38:56 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	exit(write(1, "Error\n", 6));
}

void	print_rooms(t_list *rooms)
{
	while (rooms)
	{
		ft_printf("---\nname - %s\nx: %i\ny: %i\nstatus: %c\nindex: %i\n",
										((t_room *)(rooms->content))->name,
										((t_room *)(rooms->content))->x,
										((t_room *)(rooms->content))->y,
										((t_room *)(rooms->content))->status,
										((t_room *)(rooms->content))->index);
		rooms = rooms->next;
	}
}

void	print_room_arr(t_room *room_arr, int room_num)
{
	int i;

	i = 0;
	while (i < room_num)
	{
		ft_printf("---\nname - %s\nx: %i\ny: %i\nstatus: %c\nindex: %i\nvisited: %i\nwave: %i\n",
										room_arr[i].name,
										room_arr[i].x,
										room_arr[i].y,
										room_arr[i].status,
										room_arr[i].index,
										room_arr[i].visited,
										room_arr[i].wave);
		i++;
	}
}

void	print_int(t_list *room)
{
	ft_printf("%i ", *((int *)room->content));
}

void	delete_room(void *room, size_t content_size)
{
	if (!room)
		return ;
	ft_strdel(&(((t_room *)room)->name));
	free(room);
	content_size = 0;
}