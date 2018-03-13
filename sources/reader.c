/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:57:19 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/13 19:23:49 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_data(t_data *data)
{
	data->lem_num = 0;
	data->rooms = NULL;
	data->adj = NULL;
}

t_data	read_data(void)
{
	t_data	data;
	char	*line;
	int		i;

	init_data(&data);
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_printf("%s\n", line);
		if (is_comment(line))
			i--;
		else if (i == 0 && ft_is_number(line))
			data.lem_num = ft_atoi(line);
		else if (is_instruct(line))
		{
			ft_printf("%s is instruction\n");
			//exec_instruct(&data, line);
		}
		else if (is_room(line))
		{
			ft_printf("%s is room\n", line);
			//parse_room(&data, line)
		}
		else if (is_link(line))
		{
			ft_printf("%s is link\n", line);
		//	parse_link(&data, line);
		}
		
		ft_strdel(&line);
		i++;
	}
	ft_printf("%i\n", data.lem_num);
	return (data);
}