/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:24:53 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/14 16:06:35 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft.h"
#include "matrix.h"
#include <stdlib.h>
#include <inttypes.h>

# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>

# define FD 3

typedef struct	s_data
{
	int			lem_num;
	t_list		*rooms;
	t_matrix	adj;
}				t_data;

/*
** Status description:
** c - common room
** s - start room
** e - end room
*/

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	char		status;
	int			index;
}				t_room;

void			error(void);
void			print_rooms(t_list *rooms);
void			delete_room(void *room, size_t content_size);

t_data			read_data(void);
int				is_comment(char *line);
int				is_instruct(char *line);
int				is_room(char *line);
int				is_link(t_list *rooms, char *line);
void 			parse_room(t_data *data, char *line, char status);
void			parse_link(t_data *data, char *line);
void			exec_instr(t_data *data, char *line);

#endif