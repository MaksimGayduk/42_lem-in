/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wave_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:45:54 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/16 17:31:35 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	mark_wave(t_data data, t_list *queue, int wave)
{
	while (queue)
	{
		if (data.room_arr[*((int *)queue->content)].wave == -1)
			data.room_arr[*((int *)queue->content)].wave = wave;
		queue = queue->next;
	}
}

void	handle_start_vertex(t_data *data, t_list **queue)
{
	int index;
	
	index = get_index_by_status(data->room_arr, data->room_num, 's');
	data->room_arr[index].wave = 0;
	data->room_arr[index].visited = 1;
	add_to_queue(queue, data, index);
	mark_wave(*data, *queue, 1);
}

void	unset_visited(t_data *data)
{
	int i;

	i = 0;
	while (i < data->room_num)
	{
		data->room_arr[i].visited = 0;
		i++;
	}
}

void	wave_front(t_data *data)
{
	t_list	*queue;
	int		index;
	int		wave;

	queue = NULL;
	handle_start_vertex(data, &queue);
	wave = 1;
	while (queue)
	{
		wave++;
		index = *((int *)queue->content);
		if (data->room_arr[index].status == 'e')
			printf("the shortest way to the end is %i\n",
					data->room_arr[index].wave);
		if (!data->room_arr[index].visited)
		{
			add_to_queue(&queue, data, index);
			mark_wave(*data, queue, wave);
			data->room_arr[index].visited = 1;
			ft_lstdel_front(&queue);
		}
		ft_lstiter(queue, &print_int);
		ft_printf("\n");
	}
	print_room_arr(data->room_arr, data->room_num);
	unset_visited(data);
}