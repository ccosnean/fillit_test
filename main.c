/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:59:22 by gpurci            #+#    #+#             */
/*   Updated: 2016/12/01 15:52:08 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int			ft_write(char *s, int n)
{
	write(1, s, n);
	return (0);
}

void		del_lst(t_list **ap)
{
	t_list	*tmp;

	while (*ap)
	{
		tmp = (*ap)->next;
		free(*ap);
		*ap = tmp;
	}
}

t_list		*ft_save_tetrimino(char *str, t_list *h)
{
	int		i;
	int		k;
	int		op;
	char	pos[3];

	i = 0;
	k = -1;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (k >= 0)
				pos[k] = i - op;
			else
				op = i;
			k++;
		}
		i++;
	}
	lst_add(&h, &pos[0]);
	return (h);
}

int			min_normi(t_list *ap, char f, char k, char n)
{
	char	c[200];

	f = 0;
	k = 2;
	n = k + 1;
	while (0 < 4)
	{
		if (k != 4)
		{
			if (!reinit_lst(ap, k))
			{
				n = ++k + 1;
				init_c(c, n);
				reinit_lst(ap, k);
			}
			else
				init_c(c, n);
		}
		if (cicl_vef_valid(c, ap, &f) == 'P')
			return (ft_write(c, n * n - n));
		f = 0;
		n++;
		k = 5;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	char	mr[550];
	char	f;
	t_list	*ap;
	int		i;
	char	cr;

	if (argc != 2)
		ft_error(1);
	ap = NULL;
	f = ft_open(argv[1]);
	i = 0;
	while (read(f, &cr, 1) != 0)
		mr[i++] = cr;
	ap = ft_make_map(mr, i, ap);
	min_normi(ap, '0', '0', '0');
	del_lst(&ap);
	return (0);
}
