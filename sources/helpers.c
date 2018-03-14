/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:16:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/14 12:38:16 by mgayduk          ###   ########.fr       */
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

void	delete_room(void *room, size_t content_size)
{
	if (!room)
		return ;
	ft_strdel(&(((t_room *)room)->name));
	free(room);
	content_size = 0;
}