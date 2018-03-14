/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:30:08 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/14 13:02:24 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void exec_instr(t_data *data, char *line)
{
	if (ft_strequ(line, "##start"))
	{	
		ft_strdel(&line);
		get_next_line(FD, &line);
		if (is_room(line))
			parse_room(data, line, 's');
		else
			error();
	}
	else if (ft_strequ(line, "##end"))
	{
		ft_strdel(&line);
		get_next_line(FD, &line);
		if (is_room(line))
			parse_room(data, line, 'e');
		else
			error();
	}
}

void parse_room(t_data *data, char *line, char status)
{
	char			**arr;
	t_room			room;
	static int		index;

	index == 0 ? index = 2 : 0;
	arr = ft_strsplit(line, ' ');
	room.name = ft_strdup(arr[0]);
	room.x = ft_atoi(arr[1]);
	room.y = ft_atoi(arr[2]);
	room.status = status;
	if (status == 's')
		room.index = 0;
	else if (status == 'e')
		room.index = 1;
	else
		room.index = index++;
	if (!data->rooms)
		data->rooms = ft_lstnew(&room, sizeof(t_room));
	else
		ft_lstadd_back(data->rooms, ft_lstnew(&room, sizeof(t_room)));
	ft_strdel(&line);
	ft_clear_strarr(&arr);
}