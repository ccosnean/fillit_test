/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:06:27 by gpurci            #+#    #+#             */
/*   Updated: 2016/12/01 15:51:54 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_list
{
	char			x[3];
	struct s_list	*next;
	char			f;
}					t_list;
void				create_lst(t_list **ap, char *pozition);
void				lst_add(t_list **ap, char *poz);
t_list				*cre_lst(char *poz);
void				afis_tetrys(t_list *ap);
char				sqrt_tetris(int nbr);
char				reinit_lst(t_list *ap, size_t len, char flag);
void				del_lst(t_list **ap);
void				init_c(char *c, char n, char m);
char				cicl_vef_valid(char *c, t_list *cap, char *flag);
char				ver_return(char a, char b, char *flag, t_list *cap);
char				ver_sf(t_list *tmp);
t_list				*ver_fol_lst(t_list **ap);
char				vef_valid(char *c, t_list **ap, char *i, int *k);
#endif
