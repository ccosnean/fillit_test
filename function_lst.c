/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:42:06 by gpurci            #+#    #+#             */
/*   Updated: 2016/12/09 21:00:14 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		reinit_lst_normi(t_list *ap, char len)
{
	int		k;
	char	i;
	char	j;

	while (ap)
	{
		k = 1;
		i = 0;
		j = ap->x[0];
		if (ap->x[0] > 1)
		{
			i++;
			ap->x[0] += len;
		}
		while (k < 3)
		{
			if (j + 1 != ap->x[k])
				i++;
			j = ap->x[k];
			ap->x[k] = ap->x[k] + i * len;
			k++;
		}
		ap = ap->next;
	}
}

int			reinit_lst(t_list *ap, char len)
{
	if (!(len == 2 && ap->x[2] != 6))
	{
		len = len - 4;
		reinit_lst_normi(ap, len);
		return (1);
	}
	return (0);
}

t_list		*cre_lst(char *poz)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	(tmp)->next = NULL;
	(tmp)->x[0] = poz[0];
	(tmp)->x[1] = poz[1];
	(tmp)->x[2] = poz[2];
	return (tmp);
}

void		create_lst(t_list **ap, char *poz)
{
	t_list	*tmp;
	t_list	*beg;

	beg = *ap;
	if ((tmp = cre_lst(poz)))
	{
		while (beg->next)
			beg = beg->next;
		tmp->f = beg->f + 1;
		beg->next = tmp;
	}
}

void		lst_add(t_list **ap, char *poz)
{
	if (*ap)
		create_lst(ap, poz);
	else
	{
		(*ap) = cre_lst(poz);
		(*ap)->f = 65;
	}
}
