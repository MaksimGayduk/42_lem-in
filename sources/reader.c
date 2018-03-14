/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:57:19 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/14 11:48:28 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int f;

static void	init_data(t_data *data)
{
	data->lem_num = 0;
	data->rooms = NULL;
	data->adj = NULL;
}

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
		else if (is_link(line))
			return (line);
		else
			error();
	}
	return (NULL);
}


t_data	read_data(void)
{
	t_data	data;
	f = open("./test", O_RDONLY);

	init_data(&data);
	read_lem_num(&data);
	read_rooms(&data);
	print_rooms(data.rooms);

	// //while (get_next_line(0, &line) > 0)
	// //{
	// 	ft_printf("%s\n", line);
		
	// 	if (is_comment(line))
	// 		i--;
	// 	else if (i == 0 && ft_is_number(line))
	// 		data.lem_num = ft_atoi(line);
	// 	else if (is_instruct(line))
	// 	{
	// 		ft_printf("%s is instruction\n");
	// 		//exec_instruct(&data, line);
	// 	}
	// 	else if (is_room(line))
	// 	{
	// 		ft_printf("%s is room\n", line);
	// 		//parse_room(&data, line)
	// 	}
	// 	else if (is_link(line))
	// 	{
	// 		ft_printf("%s is link\n", line);
	// 	//	parse_link(&data, line);
	// 	}
		
	// 	ft_strdel(&line);
	// 	i++;
	// //}
	ft_printf("%i\n", data.lem_num);
	return (data);
}