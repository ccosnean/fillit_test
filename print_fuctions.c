/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fuctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:40:42 by ccosnean          #+#    #+#             */
/*   Updated: 2016/12/13 14:40:56 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_error(int k)
{
	if (k == 0)
		write(1, "error\n", 6);
	else if (k == 1)
		ft_putstr("usage: ./fillit source_file\n");
	exit(0);
}

int		ft_open(char *file)
{
	int		f;

	f = open(file, O_RDONLY);
	if (f == -1)
		ft_error(0);
	return (f);
}

int		ft_is_valid_char(char *c)
{
	return (*(c - 5) == '#' || *(c + 5) == '#' || *(c + 1) == '#'
			|| *(c - 1) == '#');
}

int		ft_is_connected(char *c)
{
	return (*(c - 5) == '#' || *(c - 1) == '#'
			|| (*(c + 1) == '#' && *(c - 4) == '#')
			|| (*(c + 1) == '#' && *(c + 2) == '#' && *(c - 2) == '#')
			|| (*(c + 1) == '#' && *(c + 2) == '#' && *(c - 3) == '#'));
}
