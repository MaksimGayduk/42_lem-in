/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:28:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/19 11:15:57 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clear_data(t_data *data)
{
	free_matrix(data->adj);
	ft_lstdel(&(data->rooms), &delete_room);
	delete_room_arr(data);
	delete_pathways(&(data->pathways));
	free(data->ants);
}

static void	init_data(t_data *data)
{
	data->ant_qty = 0;
	data->rooms = NULL;
	data->room_arr = NULL;
	data->pathways = NULL;
}

int			main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (argc > 1)
		data.flags = parse_flags(&argv, argc);
	if (data.flags.h)
		print_help();
	read_data(&data);
	wave_front(&data);
	detect_pathways(&data);
	if (data.flags.p)
	{
		ft_printf("\nNumber of possible pathways: %u\n",
					ft_lstlen(data.pathways));
		print_pathways(data);
	}
	transfer_ants(&data);
	if (data.flags.j)
		show_joke();
	clear_data(&data);
	return (0);
}
