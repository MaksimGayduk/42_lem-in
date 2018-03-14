/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:29:37 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/14 12:58:54 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_comment(char *line)
{
	int len;
	
	//ft_printf("COMMENT CHECK\n");
	if (ft_word_count(line, ' ') > 1)
		return (0);
	len = ft_strlen(line);
	if (len >= 2 && line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int	is_instruct(char *line)
{
	//ft_printf("INSTR CHECK FOR %s\n", line);
	if (ft_strequ(line, "##start"))
		return (1);
	else if (ft_strequ(line, "##end"))
		return (1);
	//ft_printf("INSTR CHECK END\n");
	return (0);
}

int is_room(char *line)
{
	char	**arr;
	intmax_t x;
	intmax_t y;

	//ft_printf("ROOM CHECK\n");
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

int	is_link(char *line)
{
	char	**arr;
	int		i;
	int		count;

	if (ft_word_count(line, '-') != 2)
		return (0);
	arr = ft_strsplit(line, '-');
	i = 0;
	count = 0;
	while (arr[i])
		if (ft_is_number(arr[i++]))
			count++;
	ft_clear_strarr(&arr);
	if (count == 2)
		return (1);
	return (0);
}