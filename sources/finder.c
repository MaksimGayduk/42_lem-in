/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:45:54 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/15 12:02:13 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_to_queue(t_list **queue, t_data data, int node)
{
	
}

void	find_path(t_data data)
{
	t_list	*queue;
	int		node;

	node = get_index_by_status(data.rooms, 's');
	set_visited(data.rooms, node);
	add_to_queue(&queue, data, node);
}