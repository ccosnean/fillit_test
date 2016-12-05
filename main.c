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
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


void	ft_save_tetrimino(char	*str, t_list *h);
void	ft_print_list(t_list *h);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}


unsigned int ft_sqrt(unsigned int a){
	int				i;
	unsigned int	rem = 0;
	unsigned int	root = 0;

	i = -1;
	while (++i < 16){
		root <<= 1;
		rem = (rem << 2) | (a >> 30);
		a <<= 2;
		if(root < rem){
			root++;
			rem -= root;
			root++;
		}
	}
	return root >> 1;
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
	return (*(c - 5) == '#' || *(c + 5) == '#' || *(c + 1) == '#' || *(c - 1) == '#');
}

int		ft_is_valid(char *c)
{	
	if (*c != '.' && *c != '#' && *c != '\n')
		return (0);
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

	len = 0;
	hei = 0;
	hash = 0;
	while (*str)
	{
		if (*str == '#')
			hash++;
		if (*str == '\n' && hei < 3)
			len = 0;
		else if (ft_is_valid(str))
			len++;
		if ((*str == '\n' || *str == '\0') && len < 4)
			hei++;
		str++;
	}
	if (len != 4 || hei != 3 || hash != 4)
		ft_error(0);
}


void	ft_start_check(char *str, t_list *h)
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
			ft_save_tetrimino(m, h);
			i = 0;
		}
	}
	if (i != 0)
		ft_error(0);
	return ;
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

void	ft_make_map(char *map, int i, t_list *h)
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
		ft_start_check(map, h);
	else
		ft_error(0);
	return ;
}

void	ft_save_tetrimino(char *str, t_list *h) //debug from here...
{
	int		i;
	int		k;
	int  	op;
	char 	pos[3];

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (k > 0)
				pos[k] = i - op;
			else
				op = i;
			k++;
		}
		i++;
	}
	lst_add(&h, &pos[0]);
	return ;
}

unsigned int	ft_count_tetri(t_list *h)
{
	int		len;

	len = 1;
	while (h)
	{
		len++;
		h = h->next;
	}
	return (len < 4 ? ft_sqrt(len * 4) + 1 : ft_sqrt(len * 4));
}

int 	main(int argc, char **argv)
{
	char	c[200];
	char	f;
	t_list	*ap = NULL;
	char	*s;
	//char	poz[3];
	char	m;
	char	n;
	char	k;
	int 	i;
	char	mr[550];
	char	cr;

	if (argc != 2)
		ft_error(1);
	f = ft_open(argv[1]);
	i = 0;
	while (read(f, &cr, 1) != 0)
		mr[i++] = cr;
	ft_make_map(mr, i, ap);


	s = &c[0];
	i = 0;
	k = ft_count_tetri(ap);
	n = k + 1;
	m = n * n - 1;
	printf("%c\n", k + 48);
	while (i < 4)
	{
		init_c(s, n, m);
		reinit_lst(ap, (size_t)k, 0);
		afis_tetrys(ap);
		printf("%s", s);
		if (cicl_vef_valid(s, ap, &f) == 'P')
		{
			printf("%s\n", "P");
			write(1, s, (m - n + 1));
			return (0);
		}
		f = 0;
		n++;
		m = n * n - 1;
		k = 5;
		printf("%s\n", "N");
	}
	
	del_lst(&ap);
	return (0);
}
