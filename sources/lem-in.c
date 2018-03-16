/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:28:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/16 17:38:48 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_data	data;

	data = read_data();
	wave_front(&data);
	detect_pathways(&data);
	free_matrix(data.adj);
	ft_lstdel(&(data.rooms), &delete_room);

	// while (1)
	// 	;	
	return (0);
}