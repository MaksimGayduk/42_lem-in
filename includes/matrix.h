/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:54:57 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/14 15:38:28 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include "libft.h"
# include <math.h>

typedef struct	s_matrix
{
	int			**values;
	size_t		rows;
	size_t		cols;
}				t_matrix;

t_matrix		create_matrix(size_t rows, size_t cols);
void			print_matrix(t_matrix m);
void			free_matrix(t_matrix m);
t_matrix		dup_matrix(t_matrix src);


#endif
