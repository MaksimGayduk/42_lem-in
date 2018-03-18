/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:57:19 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 16:19:30 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	read_ant_qty(t_data *data)
{
	char	*line;

	while (get_next_line(FD, &line) > 0)
	{
		PRINT_LINE(line);
		if (is_comment(line))
		{
			ft_strdel(&line);
			continue ;
		}
		if (ft_is_number(line))
		{
			data->ant_qty = ft_atoi(line);
			if (data->ant_qty <= 0)
				ERROR_MSG("non-positive value");
			ft_strdel(&line);
			return ;
		}
		else
		{
			ERROR_MSG("incorrect ants quantity value");
			ft_strdel(&line);
		}
	}
}

static char	*read_rooms(t_data *data)
{
	char	*line;

	while (get_next_line(FD, &line) > 0)
	{
		PRINT_LINE(line);
		if (is_comment(line))
		{
			ft_strdel(&line);
			continue ;
		}
		else if (is_instruct(line))
			exec_instr(data, line);
		else if (is_room(line))
			parse_room(data, line, 'c');
		else if (is_link(data, line))
			return (line);
		else
			ERROR_MSG("incorrect room parameters");
	}
	return (NULL);
}

static void build_adj_matrix(t_data *data, char *temp)
{
	size_t	room_qty;
	char	*line;

	room_qty = ft_lstlen(data->rooms);
	data->adj = create_matrix(room_qty, room_qty);
	parse_link(data, temp);
	while (get_next_line(FD, &line) > 0)
	{
		PRINT_LINE(line);
		if (is_comment(line))
		{
			ft_strdel(&line);
			continue ;
		}
		if (is_link(data, line))
			parse_link(data, line);
		else
			ERROR_MSG("incorect link")
	}
}

static void	write_rooms_to_arr(t_data *data)
{
	int		index;
	t_list	*temp;
	size_t	len;

	len = ft_lstlen(data->rooms);
	data->room_num = len;
	data->room_arr = (t_room *)malloc(sizeof(t_room) * len);
	temp = data->rooms;
	while (temp)
	{
		index = ((t_room *)temp->content)->index;
		ft_memcpy(&(data->room_arr[index]), (t_room *)temp->content, sizeof(t_room));
		data->room_arr[index].name = ft_strdup(((t_room *)temp->content)->name);
		temp = temp->next;
	}
}

void	read_data(t_data *data)
{
	char 	*temp;

	read_ant_qty(data);
	temp = read_rooms(data);
	if (!temp)
		data->flags.e ? error(NULL, "there are no links between rooms") :
						error(NULL, NULL);
	check_status(data->rooms, data->flags.e);
	build_adj_matrix(data, temp);
	write_rooms_to_arr(data);
}