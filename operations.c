/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:04:08 by gpurci            #+#    #+#             */
/*   Updated: 2016/12/01 15:52:01 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>////////////

char				sqrt_tetris(int nbr)
{
	char			i;

	i = 1;
	while (i * i < (char)nbr)
		i++;
	return (i);
}

void		afis_tetrys(t_list *ap)///////////////////////////
{
	int		k;

	k = 0;
	while ((ap))
	{
		k = 0;
		while (k < 4)
		{
			printf("k = %d x = %c|\n", k, (ap)->x[k] + 48);
			k++;
		}
		printf("f = %c|\n", ap->f - 30);
		(ap) = (ap)->next;
		write(1, "#\n", 2);
	}
}

char		vef_valid(char *c, t_list **ap, char *i, int *k)
{
	if (!(*ap = ver_fol_lst(ap)))
		return (0);
	*k = 0;
	*c = (*ap)->f;
	*i = 0;
	while (*(c + (*ap)->x[*k]) == '.')
	{
		*(c + (*ap)->x[*k]) = (*ap)->f;
		if ((*ap)->x[*k] < 4)
			*i = (*ap)->x[*k];
		(*k)++;
		if (*k == 3)
			return (++(*i));
	}
	return (0);
}

t_list		*ver_fol_lst(t_list **ap)
{
	while (*ap)
	{
		if ((*ap)->f > 'Z')
		{
			(*ap)->f -= 30;
			break ;
		}
		else
			(*ap) = (*ap)->next;
	}
	return (*ap);
}

char		ver_sf(t_list *tmp)
{
	while (tmp)
	{
		if (tmp->f > 'Z')
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char		ver_return(char a, char b, char *flag, t_list *cap)
{
	if (*flag != 0)
		return (*flag);
	else if (a == '\n' && b == '\n')
	{
		if ((ver_sf(cap)))
			return ((*flag = 'P'));
		return ((*flag = 'N'));
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
	char		i;
	int			k;
	t_list		*tmp;
	
	if ((ver_return(c[0], c[1], flag, cap)))
		return (*flag);
	tmp = cap;
	if (*c == '.')
	{
		while (tmp)
		{
			if ((i = vef_valid(c, &tmp, &i, &k)))
			{
				i = m_dif(c, i);
				if ((cicl_vef_valid(c + i, cap, flag) == 'P'))
					return ((*flag = 'P'));
				*flag = 0;
			}
			if (tmp)
			{
				while (--k > -1)
					*(c + tmp->x[k]) = '.';
				*c = '.';
				tmp->f += 30;
				tmp = tmp->next;
			}
		}
	}
	i = m_dif(c, 0);
	if (cicl_vef_valid(c + i, cap, flag) == 'P')
		return ((*flag = 'P'));
	return ((*flag = 'N'));
}

void		init_c(char *c, char n, char m)
{
	char	i;
	char	j;

	i = 1;
	j = (n * (n - 1));
	m++;
	while (i < j)
	{
		if (i % n == 0)
			*c = '\n';
		else
			*c = '.';
		i++;
		c++;
	}
	while (i < m)
	{
		*c = '\n';
		i++;
		c++;
	}
	*c = '\0';
}
