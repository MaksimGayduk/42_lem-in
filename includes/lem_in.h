/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:24:53 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/13 19:21:36 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft.h"
#include <stdlib.h>

typedef struct	s_data
{
	int			lem_num;
	t_list		*rooms;
	int			**adj;
}				t_data;

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
}				t_room;

t_data			read_data(void);
int				is_comment(char *line);
int				is_instruct(char *line);
int				is_room(char *line);
int				is_link(char *line);

#endif