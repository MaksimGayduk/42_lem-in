/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:16:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 16:41:02 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(char *line, char *desc)
{
	if (!line && !desc)
		exit(write(1, "Error\n", 6));
	else if (!line && desc)
		exit(ft_printf("Error: %s\n", desc));
	else
	{
		ft_printf("Error: %s <%s>\n", desc, line);
		ft_strdel(&line);
		exit(1);
	}
}

void	print_pathways(t_data data)
{
	t_list *temp;
	t_list *pathways;

	pathways = data.pathways;
	while (pathways)
	{
		temp = (t_list *)(pathways->content);
		ft_printf("\n");
		while (temp)
		{
			if (!temp->next)
				ft_printf("[%s]",
					data.room_arr[*((int *)temp->content)].name);
			else
				ft_printf("[%s]->",
					data.room_arr[*((int *)temp->content)].name);
			temp = temp->next;
		}
		ft_printf(" - length : %u", pathways->content_size);
		ft_printf("\n");
		pathways = pathways->next;
	}
	ft_printf("\n");
}

void	print_help(void)
{
	ft_printf("Usage: ./lem-in [flags] < map_file\n\n");
	ft_printf("Flags description:\n");
	ft_printf("-e - explain errors\n");
	ft_printf("-p - show possible pathways\n");
	ft_printf("-s - supress output of file data\n");
	ft_printf("-h - show help\n");
	ft_printf("-j - show joke\n");
	exit(1);
}

void	show_joke(void)
{
	setlocale(LC_CTYPE, "");
	ft_printf("В детстве смеялся над басней Крылова про стрекозу и муравья.\n");
	ft_printf("Не понимал, как можно не заметить, что прошло лето.\n");
	ft_printf("Сейчас не смешно.\n");
}
