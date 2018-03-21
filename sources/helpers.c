/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:16:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/21 19:16:31 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(char *line, char *desc)
{
	if (!line && !desc)
		exit(write(1, "Error\n", 6));
	else if (!line && desc)
		exit(ft_printf(RED "Error: %s\n" F_RESET, desc));
	else
	{
		ft_printf(RED "Error: %s <%s>\n" F_RESET, desc, line);
		ft_strdel(&line);
		exit(1);
	}
}

void	print_pathways(t_data data)
{
	t_list *temp;
	t_list *pathways;

	ft_printf(CYAN "\nNumber of possible pathways: %u\n",
				ft_lstlen(data.pathways));
	pathways = data.pathways;
	while (pathways)
	{
		temp = (t_list *)(pathways->content);
		ft_printf(YELLOW "\n");
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
		ft_printf(RESET " - steps : %u", pathways->content_size);
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
	exit(1);
}
