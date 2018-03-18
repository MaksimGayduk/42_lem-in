/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:37:45 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/18 16:20:18 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_flags(t_flags *flags)
{
	flags->e = 0;
	flags->p = 0;
	flags->s = 0;
	flags->h = 0;
}

static void	detect_flag(char *arg, t_flags *flags)
{
	if (ft_strequ(arg, "-e"))
		flags->e = 1;
	else if (ft_strequ(arg, "-p"))
		flags->p = 1;
	else if (ft_strequ(arg, "-s"))
		flags->s = 1;
	else if (ft_strequ(arg, "-h"))
		flags->h = 1;
	else
		flags->e ? error(ft_strdup(arg), "incorrect flag")
					: error(NULL, NULL);
}

t_flags		parse_flags(char ***args, int argc)
{
	t_flags	flags;

	init_flags(&flags);
	while (argc)
	{
		if (**args && ***args == '-' && !ft_is_number(**args))
			detect_flag(**args, &flags);
		(*args)++;
		argc--;
	}
	return (flags);
}
