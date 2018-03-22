/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 08:52:23 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/22 08:48:51 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		make_step(t_data *data)
{
	int i;
	int moved;

	i = 0;
	moved = 0;
	while (i < data->ant_qty)
	{
		if (data->ants[i].path->next &&
			(!data->room_arr[NEXT_ROOM_IN_PATH(i)].visited ||
			data->room_arr[NEXT_ROOM_IN_PATH(i)].status == 'e'))
		{
			data->room_arr[ROOM_IN_PATH(i)].visited = 0;
			data->ants[i].path = data->ants[i].path->next;
			data->room_arr[ROOM_IN_PATH(i)].visited = 1;
			moved++;
			ft_printf(GREEN "L%i-%s " RESET, data->ants[i].name,
			data->room_arr[ROOM_IN_PATH(i)].name);
		}
		i++;
	}
	ft_printf("\n");
	return (moved);
}

void	transfer_ants(t_data *data)
{
	int moved;

	create_ants(data);
	appoint_path(data);
	moved = EMPTY;
	while (moved)
		moved = make_step(data);
}
