/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:57:19 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/15 09:15:28 by mgayduk          ###   ########.fr       */
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

t_data	read_data(void)
{
	char 	*temp;
	t_data	data;

	open("./test", O_RDONLY);

	data.lem_num = 0;
	data.rooms = NULL;
	read_lem_num(&data);
	temp = read_rooms(&data);
	build_adj_matrix(&data, temp);
	check_status(data.rooms);
	print_rooms(data.rooms);

	ft_printf("%i\n", data.lem_num);
	return (data);
}