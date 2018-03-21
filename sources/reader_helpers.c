/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:00:43 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/21 18:24:59 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_ants_qty(t_data *data, char *line)
{
	data->ant_qty = ft_atoi(line);
	if (data->ant_qty <= 0)
		ERROR_MESSAGE(line, "non-positive value");
	if (data->ant_qty > 100000)
		ERROR_MESSAGE(line, "Dude, it`s too much ants :) [limit 100 000]");
	ft_strdel(&line);
}

void	check_file(t_data *data, char *line, int i)
{
	if (i && !data->ant_qty)
		ERROR_MESSAGE(line, "no ants quantity");
	if (!i)
		ERROR_MESSAGE(line, "file is empty");
}

void	check_uniqe_room(t_data *data, t_room room, char *line)
{
	t_list *temp;

	temp = data->rooms;
	while (temp)
	{
		if (ft_strequ(room.name, ((t_room *)temp->content)->name))
			ERROR_MESSAGE(line, "the room with such name is already exists");
		if (room.x == (((t_room *)temp->content)->x) &&
			room.y == (((t_room *)temp->content)->y))
			ERROR_MESSAGE(line, "the room with the same coordinates is already exists");
		temp = temp->next;
	}
}