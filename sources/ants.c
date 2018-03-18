/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 08:55:03 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 16:38:01 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_ants(t_data *data)
{
	int i;

	data->ants = (t_ant *)malloc(sizeof(t_ant) * data->ant_qty);
	i = 0;
	while (i < data->ant_qty)
	{
		data->ants[i].name = i + 1;
		i++;
	}
}

t_list	*get_shortest_path(t_data *data)
{
	t_list	*temp;
	t_list	*short_path;

	temp = data->pathways;
	short_path = data->pathways;
	while (temp)
	{
		if (short_path->content_size > temp->content_size)
			short_path = temp;
		temp = temp->next;
	}
	short_path->content_size++;
	return ((t_list *)short_path->content);
}

void	appoint_path(t_data *data)
{
	int i;

	i = 0;
	while (i < data->ant_qty)
	{
		data->ants[i].path = get_shortest_path(data);
		i++;
	}
}
