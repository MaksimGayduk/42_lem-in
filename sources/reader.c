/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:57:19 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/22 08:47:43 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	read_ant_qty(t_data *data, char **line)
{
	while (get_next_line(FD, line) > 0)
	{
		if (!(*line))
			ERROR_MSG(*line, "empty line");
		PRINT_LINE(*line);
		if (is_comment(*line))
		{
			ft_strdel(line);
			continue ;
		}
		if (ft_is_number(*line) && *line)
		{
			write_ants_qty(data, *line);
			return ;
		}
		ERROR_MSG(*line, "incorrect ants quantity value");
	}
	ERROR_MSG(*line, "empty file");
}

static void	read_rooms(t_data *data, char **line)
{
	while (get_next_line(FD, line) > 0)
	{
		if (!(*line))
			ERROR_MSG(*line, "empty line");
		PRINT_LINE(*line);
		if (is_comment(*line))
		{
			ft_strdel(line);
			continue ;
		}
		else if (is_instruct(*line))
			exec_instr(data, *line);
		else if (is_room(*line))
			parse_room(data, *line, 'c');
		else if (is_link(*line))
			return ;
		else
			ERROR_MSG(*line, "incorrect room parameters");
	}
}

static void	build_adj_matrix(t_data *data, char **line)
{
	size_t	room_qty;

	room_qty = ft_lstlen(data->rooms);
	data->adj = create_matrix(room_qty, room_qty);
	parse_link(data, *line);
	while (get_next_line(FD, line) > 0)
	{
		if (!(*line) && ft_printf(MAGENTA "Warning: empty line\n" F_RESET))
			return ;
		PRINT_LINE(*line);
		if (is_comment(*line))
		{
			ft_strdel(line);
			continue ;
		}
		if (is_link(*line))
			parse_link(data, *line);
		else
		{
			ft_printf(MAGENTA "Warning: incorrect link <%s>\n" F_RESET, *line);
			return ;
		}
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
		ft_memcpy(&(data->room_arr[index]), (t_room *)temp->content,
					sizeof(t_room));
		data->room_arr[index].name = ft_strdup(((t_room *)temp->content)->name);
		temp = temp->next;
	}
}

void		read_data(t_data *data)
{
	char	*line;

	open("testing/farm0", O_RDONLY, 0);

	line = NULL;
	read_ant_qty(data, &line);
	read_rooms(data, &line);
	if (!ft_lstlen(data->rooms))
		ERROR_MSG(NULL, "rooms weren`t specified");
	if (!line)
		ERROR_MSG(line, "there are no links between rooms");
	check_status(data);
	build_adj_matrix(data, &line);
	ft_printf("\n");
	write_rooms_to_arr(data);
}
