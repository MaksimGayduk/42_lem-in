/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:28:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 11:22:34 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_data	data;

	data = read_data();
	wave_front(&data);
	print_room_arr(data.room_arr, data.room_num);
	detect_pathways(&data);
	ft_printf("size of data: %u\n", sizeof(data));
	transfer_ants(&data);
	
	free_matrix(data.adj);
	ft_lstdel(&(data.rooms), &delete_room);
	delete_pathways(&(data.pathways));

	// while (1)
	// 	;	
	return (0);
}