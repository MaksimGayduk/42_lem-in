/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:30:08 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/19 17:54:33 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	exec_instr(t_data *data, char *line)
{
	if (ft_strequ(line, "##start"))
	{
		ft_strdel(&line);
		get_next_line(FD, &line);
		PRINT_LINE(line);
		if (is_room(line))
			parse_room(data, line, 's');
		else
			ERROR_MSG("incorrect room parameters");
	}
	else if (ft_strequ(line, "##end"))
	{
		ft_strdel(&line);
		get_next_line(FD, &line);
		PRINT_LINE(line);
		if (is_room(line))
			parse_room(data, line, 'e');
		else
			ERROR_MSG("incorrect room parameters");
	}
}

void	parse_room(t_data *data, char *line, char status)
{
	char			**arr;
	t_room			room;
	static int		index;

	arr = ft_strsplit(line, ' ');
	room.name = ft_strdup(arr[0]);
	room.x = ft_atoi(arr[1]);
	room.y = ft_atoi(arr[2]);
	check_uniqe_room(data, room, line);
	room.status = status;
	room.index = index;
	room.visited = 0;
	room.wave = -1;
	index++;
	if (!data->rooms)
		data->rooms = ft_lstnew(&room, sizeof(t_room));
	else
		ft_lstadd_back(data->rooms, ft_lstnew(&room, sizeof(t_room)));
	ft_strdel(&line);
	ft_clear_strarr(&arr);
}

void	parse_link(t_data *data, char *line)
{
	int		i;
	int		j;
	char	**arr;

	arr = ft_strsplit(line, '-');
	i = get_index_by_name(data->rooms, arr[0]);
	j = get_index_by_name(data->rooms, arr[1]);
	data->adj.values[i][j] = 1;
	data->adj.values[j][i] = 1;
	ft_strdel(&line);
	ft_clear_strarr(&arr);
}

void	check_status(t_list *rooms, short e)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (rooms)
	{
		if (((t_room *)rooms->content)->status == 's')
			start++;
		if (((t_room *)rooms->content)->status == 'e')
			end++;
		rooms = rooms->next;
	}
	if (start == 0)
		e ? error(NULL, "START room wasn`t specified") : error(NULL, NULL);
	if (end == 0)
		e ? error(NULL, "END room wasn`t specified") : error(NULL, NULL);
	if (start > 1)
		e ? error(NULL, "there are more than one START room") :
			error(NULL, NULL);
	if (end > 1)
		e ? error(NULL, "there are more than one END room") :
			error(NULL, NULL);
}
