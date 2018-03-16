/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:57:39 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/16 14:58:28 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		in_queue(t_list *queue, int index)
{
	while (queue)
	{
		if (*((int *)queue->content) == index)
			return (1);
		queue = queue->next;
	}
	return (0);
}

void	add_to_queue(t_list **queue, t_data *data, int index)
{
	int			j;

	j = 0;
	while (j < data->room_num)
	{
		if (data->adj.values[index][j] == 1 && !data->room_arr[j].visited &&
			!in_queue(*queue, j))
		{
			if (!*queue)
				*queue = ft_lstnew(&j, sizeof(int));
			else
				ft_lstadd_back(*queue, ft_lstnew(&j, sizeof(int)));
		}
		j++;
	}
	ft_lstiter(*queue, &print_int);
	ft_printf("\n");
}