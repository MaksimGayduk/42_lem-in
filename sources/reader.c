/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:57:19 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/16 19:38:46 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	read_lem_num(t_data *data)
{
	char	*line;

	while (get_next_line(FD, &line) > 0)
	{
		if (is_comment(line))
		{
			ft_strdel(&line);
			continue ;
		}
		if (ft_is_number(line))
		{
			data->lem_num = ft_atoi(line);
			ft_strdel(&line);
			return ;
		}
		else
		{
			ft_strdel(&line);
			error();
		}
	}
}

static char	*read_rooms(t_data *data)
{
	char	*line;

	while (get_next_line(FD, &line) > 0)
	{
		if (is_comment(line))
		{
			ft_strdel(&line);
			continue ;
		}
		else if (is_instruct(line))
			exec_instr(data, line);
		else if (is_room(line))
			parse_room(data, line, 'c');
		else if (is_link(data->rooms, line))
			return (line);
		else
			error();
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
		if (is_comment(line))
		{
			ft_strdel(&line);
			continue ;
		}
		if (is_link(data->rooms, line))
			parse_link(data, line);
		else
			error();
	}
	print_matrix(data->adj);
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

t_data	read_data(void)
{
	char 	*temp;
	t_data	data;

	open("./test", O_RDONLY);

	data.lem_num = 0;
	data.rooms = NULL;
	data.room_arr = NULL;
	data.pathways = NULL;
	read_lem_num(&data);
	temp = read_rooms(&data);
	check_status(data.rooms);
	build_adj_matrix(&data, temp);
	write_rooms_to_arr(&data);
	print_room_arr(data.room_arr, data.room_num);
	//print_rooms(data.rooms);

	ft_printf("%i\n", data.lem_num);
	return (data);
}