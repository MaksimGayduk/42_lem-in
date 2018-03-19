/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:24:53 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/19 12:07:10 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "matrix.h"
# include <inttypes.h>

# define FD 0
# define EMPTY -42
# define ROOM_IN_PATH(i) *((int *)data->ants[i].path->content)
# define NEXT_ROOM_IN_PATH(i) *((int *)data->ants[i].path->next->content)
# define ERROR_MSG(s) data->flags.e ? error(line, s) : error(NULL, NULL);
# define PRINT_LINE(line) data->flags.s == 1 ? 0 : ft_printf("%s\n", line);

typedef	struct	s_flags
{
	short		e;
	short		p;
	short		s;
	short		h;
	short		j;
}				t_flags;

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
	t_flags		flags;
}				t_data;

t_flags			parse_flags(char ***args, int argc);
void			error(char *line, char *desc);
void			print_pathways(t_data data);
void			print_help(void);
void			show_joke(void);
void			delete_room(void *room, size_t content_size);
void			delete_room_arr(t_data *data);
void			delete_path(void *content, size_t content_size);
void			delete_pathways(t_list **head);
void			clear_data(t_data *data);

/*
** Functions for reading data
*/
void			read_data(t_data *data);
int				is_comment(char *line);
int				is_instruct(char *line);
int				is_room(char *line);
int				is_link(t_data *data, char *line);
void			parse_room(t_data *data, char *line, char status);
void			parse_link(t_data *data, char *line);
void			exec_instr(t_data *data, char *line);
void			check_status(t_list *rooms, short e);
void			write_ants_qty(t_data *data, char *line);
void			check_file(t_data *data, char *line, int i);

/*
** Functions for pathways serching
*/
void			wave_front(t_data *data);
int				in_queue(t_list *queue, int index);
void			add_to_queue(t_list **queue, t_data *data, int index);
void			detect_pathways(t_data *data);
void			unset_visited(t_data *data);

/*
** Room functions
*/
int				get_index_by_name(t_list *rooms, char *name);
int				get_index_by_status(t_room *room_arr, int room_num,
									char status);

/*
**	Ants functions
*/
void			transfer_ants(t_data *data);
void			create_ants(t_data *data);
void			appoint_path(t_data *data);

#endif
