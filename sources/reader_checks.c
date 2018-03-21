/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:29:37 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/21 19:26:09 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_comment(char *line)
{
	int len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len >= 2 && line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int	is_instruct(char *line)
{
	if (!line)
		return (0);
	if (line[0] == '#' && line[1] == '#')
		return (1);
	return (0);
}

int	is_room(char *line)
{
	char		**arr;
	intmax_t	x;
	intmax_t	y;

	if (!line)
		return (0);
	if (ft_word_count(line, ' ') != 3)
		return (0);
	arr = ft_strsplit(line, ' ');
	if (!ft_is_number(arr[1]) || !ft_is_number(arr[2]))
	{
		ft_clear_strarr(&arr);
		return (0);
	}
	x = ft_atoi(arr[1]);
	y = ft_atoi(arr[2]);
	if (x > INT_MAX || x < INT_MIN || y > INT_MAX || y < INT_MIN)
	{
		ft_clear_strarr(&arr);
		return (0);
	}
	ft_clear_strarr(&arr);
	return (1);
}

int	in_list_by_name(t_list *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strequ(((t_room *)rooms->content)->name, name))
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

int	is_link(t_data *data, char *line)
{
	char	**arr;

	if (!line)
		return (0);
	if (ft_word_count(line, '-') != 2)
		return (0);
	arr = ft_strsplit(line, '-');
	if (in_list_by_name(data->rooms, arr[0]) &&
		in_list_by_name(data->rooms, arr[1]))
	{
		ft_clear_strarr(&arr);
		return (1);
	}
	ft_clear_strarr(&arr);
	ERROR_MSG(line, "there is no room with such name");
	return (0);
}
