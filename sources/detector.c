/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:32:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 15:41:13 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int		get_next_vertex(t_data data, int index)
{
	int steps;
	int vertex;
	int j;

	steps = INT_MAX;
	vertex = EMPTY;
	j = 0;
	while (j < data.room_num)
	{
		if (data.adj.values[index][j] &&
			!data.room_arr[j].visited &&
			data.room_arr[j].wave < steps)
		{
			steps = data.room_arr[j].wave;
			vertex = j;
		}
		j++;
	}
	return (vertex);
}

void	find_path_to_start(t_data *data, t_list **path, int index)
{
	int vertex;

	if (data->room_arr[index].status == 's')
		return ;
	data->room_arr[index].visited = 1;
	vertex = get_next_vertex(*data, index);
	if (vertex == EMPTY)
	{
		ft_lstdel(path, &delete_path);
		return ;
	}
	ft_lstadd(path, ft_lstnew(&vertex, sizeof(vertex)));
	find_path_to_start(data, path, vertex);

}

int get_qty_ways(t_data data, int index)
{
	int ways;
	int j;

	ways = 0;
	j = 0;
	while (j < data.room_num)
	{
		if (data.adj.values[index][j])
			ways++;
		j++;
	}
	return (ways);
}

void	add_to_pathways(t_data *data, t_list *path)
{
	t_list *temp;

	if (!(data->pathways))
	{
		data->pathways = ft_lstnew(NULL, 0);
		data->pathways->content = path;
		data->pathways->content_size = ft_lstlen(path) - 1;
	}
	else
	{
		temp = ft_lstnew(NULL, 0);
		temp->content = path;
		temp->content_size = ft_lstlen(path) - 1;
		ft_lstadd_back(data->pathways, temp);
	}
}

void	detect_pathways(t_data *data)
{
	int index;
	int possible_ways;
	t_list *path;
	
	index = get_index_by_status(data->room_arr, data->room_num, 'e');
	possible_ways = get_qty_ways(*data, index);
	while (possible_ways)
	{
		path = ft_lstnew(&index, sizeof(index));
		find_path_to_start(data, &path, index);
		possible_ways--;
		if (!path)
			continue ;
		else
			add_to_pathways(data, path);		
	}
	unset_visited(data);
}