/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:24:53 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 11:12:26 by mgayduk          ###   ########.fr       */
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
# define EMPTY -42
# define ROOM_IN_PATH(i) *((int *)data->ants[i].path->content)
# define NEXT_ROOM_IN_PATH(i) *((int *)data->ants[i].path->next->content)

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
	int			visited;
	int			wave;
}				t_room;

typedef struct	s_ant
{
	int			name;
	t_list		*path;
	int			steps;
}				t_ant;

typedef struct	s_data
{
	int			ant_qty;
	int			room_num;
	t_list		*rooms;
	t_room		*room_arr;
	t_matrix	adj;
	t_list		*pathways;
	t_ant		*ants;
}				t_data;

void			error(void);
void			print_rooms(t_list *rooms);
void			print_room_arr(t_room *room_arr, int room_num);
void			print_int(t_list *room);
void			print_pathways(t_list *pathways);
void			delete_room(void *room, size_t content_size);
void			delete_path(void *content, size_t content_size);
void			delete_pathways(t_list **head);
void			print_ants(t_ant *ants, int ant_qty);

/*
** Functions for reading data
*/
t_data			read_data(void);
int				is_comment(char *line);
int				is_instruct(char *line);
int				is_room(char *line);
int				is_link(t_list *rooms, char *line);
void 			parse_room(t_data *data, char *line, char status);
void			parse_link(t_data *data, char *line);
void			exec_instr(t_data *data, char *line);
void			check_status(t_list *rooms);

/*
** Functions for pathways serching
*/
void			wave_front(t_data *data);
int				in_queue(t_list *queue, int index);
void			add_to_queue(t_list **queue, t_data *data, int index);
void			detect_pathways(t_data *data);
void			unset_visited(t_data *data);

/*
** room functions
*/
int				get_index_by_name(t_list *rooms, char *name);
int				get_index_by_status(t_room *room_arr, int room_num, char status);

void			transfer_ants(t_data *data);
void			create_ants(t_data *data);
void			appoint_path(t_data *data);


#endif