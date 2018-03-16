/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:32:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/16 18:38:00 by mgayduk          ###   ########.fr       */
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
	ft_lstadd(path, ft_lstnew(&vertex, sizeof(vertex)));
	ft_printf("\n");
	ft_lstiter(*path, &print_int);
	ft_printf("\n");
	find_path_to_start(data, path, vertex);

}

void	detect_pathways(t_data *data)
{
	int index;
	t_list *path;

	index = get_index_by_status(data->room_arr, data->room_num, 'e');
	path = ft_lstnew(&index, sizeof(index));
	find_path_to_start(data, &path, index);
}