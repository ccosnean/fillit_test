/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:06:27 by gpurci            #+#    #+#             */
/*   Updated: 2016/12/13 15:47:48 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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
int					reinit_lst(t_list *ap, char len);
void				del_lst(t_list **ap);
void				init_c(char *c, char n);
char				cicl_vef_valid(char *c, t_list *cap, char *flag);
char				ver_return(char a, char b, char *flag, t_list *cap);
char				ver_sf(t_list *tmp);
t_list				*ver_fol_lst(t_list **ap);
char				vef_valid(char *c, t_list **ap, int *k);

t_list				*ft_save_tetrimino(char	*str, t_list *h);
void				ft_putstr(char *str);
void				ft_error(int k);
int					ft_open(char *file);
int					ft_is_valid_char(char *c);
int					ft_is_connected(char *c);
int					ft_is_valid(char *c);
void				ft_check(char *str);
t_list				*ft_start_check(char *str, t_list *h);
int					ft_check_spaces(char *str);
t_list				*ft_make_map(char *map, int i, t_list *h);

#endif
