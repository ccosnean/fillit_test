/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:04:08 by gpurci            #+#    #+#             */
/*   Updated: 2016/12/09 21:00:04 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

char		sqrt_tetris(int nbr)
{
	char	i;

	i = 1;
	while (i * i < (char)nbr)
		i++;
	return (i);
}

char		vef_valid(char *c, t_list **ap, int *k)
{
	*k = 0;
	*c = (*ap)->f;
	while (*(c + (*ap)->x[*k]) == '.')
	{
		*(c + (*ap)->x[*k]) = (*ap)->f;
		(*k)++;
		if (*k == 3)
			return (1);
	}
	return (0);
}

char		m_dif(char *c, char i)
{
	while (*(c + i) != '.')
	{
		i++;
		if (*(c + i) == '\0')
		{
			i -= 2;
			break ;
		}
	}
	if (i == 0)
		i = 1;
	return (i);
}

char		cicl_vef_valid(char *c, t_list *cap, char *flag)
{
	int		k;
	int		j;

	if (*flag != 0)
		return (*flag);
	if (!cap)
		return ((*flag = 'P'));
	j = 0;
	while (c[j] != '\0')
	{
		if (c[j] == '.')
		{
			if ((vef_valid(c + j, &cap, &k)))
			{
				if ((cicl_vef_valid(c, cap->next, flag) == 'P'))
					return ((*flag = 'P'));
				*flag = 0;
			}
			while (--k > -1)
				*(c + cap->x[k] + j) = '.';
			*(c + j) = '.';
		}
		j++;
	}
	return ((*flag = 'N'));
}

void		init_c(char *c, char n)
{
	char	i;
	char	j;

	i = 1;
	j = (n * (n - 1)) + 1;
	while (i < j)
	{
		if (i % n == 0)
			*c = '\n';
		else
			*c = '.';
		i++;
		c++;
	}
	j = n * n;
	while (i < j)
	{
		*c = '\0';
		i++;
		c++;
	}
	*c = '\0';
}
