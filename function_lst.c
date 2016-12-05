/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:42:06 by gpurci            #+#    #+#             */
/*   Updated: 2016/12/01 15:51:57 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

char		reinit_lst(t_list *ap, size_t len, char flag)
{
	int		k;

	if (len > 4)
	{
		len = len - 4;
		while (ap)
		{
			k = 0;
			while (k < 3)
			{
				if (ap->x[k] > 13)
					ap->x[k] = ap->x[k] + 3 * len;
				else if (ap->x[k] > 8)
					ap->x[k] = ap->x[k] + 2 * len;
				else if (ap->x[k] > 3 - flag)
					ap->x[k] = ap->x[k] + len;
				k++;
			}
			ap = ap->next;
		}
		flag = 0;
	}
	else if (len < 4)
	{
		len = 4 - len;
		while (ap)
		{
			k = 0;
			while (k < 3)
			{
				if (ap->x[k] > 14)
					ap->x[k] = ap->x[k] - 3 * len;
				else if (ap->x[k] > 9)
					ap->x[k] = ap->x[k] - 2 * len;
				else if (ap->x[k] > 4)
					ap->x[k] = ap->x[k] - len;
				k++;
			}
			ap = ap->next;
		}
		if (len == 2)
			flag = 1;
	}
	return (flag);
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

void			lst_add(t_list **ap, char *poz)
{
	if (*ap)
		create_lst(ap, poz);
	else
	{
		(*ap) = cre_lst(poz);
		(*ap)->f = 95;
	}
}
