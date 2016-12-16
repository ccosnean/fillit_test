/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:41:22 by ccosnean          #+#    #+#             */
/*   Updated: 2016/12/13 14:41:23 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ft_is_valid(char *c)
{
	if (*c != '.' && *c != '#' && *c != '\n')
		ft_error(0);
	if (*c == '.')
		return (1);
	if (*c == '\n' || *c == '\0')
		return (0);
	return (ft_is_valid_char(c));
}

void	ft_check(char *str)
{
	int		len;
	int		hei;
	int		hash;
	int		conn;

	len = 0;
	hei = 0;
	hash = 0;
	conn = 0;
	while (*str)
	{
		if (*str == '#')
			hash++;
		if (*str == '#' && ft_is_connected(str))
			conn++;
		if (*str == '\n' && hei < 3)
			len = 0;
		else if (ft_is_valid(str))
			len++;
		if ((*str == '\n' || *str == '\0') && len < 4)
			hei++;
		str++;
	}
	if (len != 4 || hei != 3 || hash != 4 || conn != 3)
		ft_error(0);
}

t_list	*ft_start_check(char *str, t_list *h)
{
	int		i;
	char	m[21];

	i = 0;
	while (*str)
	{
		m[i] = *str;
		str++;
		i++;
		if (i == 21)
		{
			ft_check(m);
			h = ft_save_tetrimino(m, h);
			i = 0;
		}
	}
	if (i != 0)
		ft_error(0);
	return (h);
}

int		ft_check_spaces(char *str)
{
	int		sp;

	sp = 0;
	while (*(str++))
	{
		if (*str == '\n')
		{
			while (*(str++) == '\n')
				sp++;
			if (sp > 2)
				ft_error(0);
			sp = 0;
		}
	}
	return (1);
}

t_list	*ft_make_map(char *map, int i, t_list *h)
{
	int	k;

	k = 0;
	while (map[i] == '\n' || map[i] == '\0')
	{
		k++;
		i--;
	}
	if (k != 2)
		ft_error(0);
	map[i + 2] = '\n';
	map[i + 3] = '\0';
	if (ft_check_spaces(map))
		h = ft_start_check(map, h);
	else
		ft_error(0);
	return (h);
}
