/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:32:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/16 20:22:01 by mgayduk          ###   ########.fr       */
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
	// ft_printf("\n");
	// ft_lstiter(*path, &print_int);
	// ft_printf("\n");
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

void	detect_pathways(t_data *data)
{
	int index;
	int possible_ways;
	t_list *path;
	t_list *temp;
	
	index = get_index_by_status(data->room_arr, data->room_num, 'e');
	possible_ways = get_qty_ways(*data, index);
	while (possible_ways)
	{
		path = ft_lstnew(&index, sizeof(index));
		find_path_to_start(data, &path, index);
		ft_printf("\npath length %u\n", ft_lstlen(path));
		// ft_printf("\n");
		// ft_lstiter(path, &print_int);
		// ft_printf("\n");
		if (!(data->pathways))
		{
			data->pathways = ft_lstnew(NULL, 0);
			data->pathways->content = path;
			
		}
		else
		{
			temp = ft_lstnew(NULL, 0);
			temp->content = path;
			ft_lstadd_back(data->pathways, temp);
		}
		//ft_lstiter((t_list *)(data->pathways->content), &print_int);
		possible_ways--;
	}
	ft_printf("\npath way length %u\n", ft_lstlen(data->pathways));
	while (data->pathways)
	{
		ft_printf("\n");
		ft_lstiter((t_list *)(data->pathways->content), &print_int);
		ft_printf("\n");
		data->pathways = data->pathways->next;
	}
}