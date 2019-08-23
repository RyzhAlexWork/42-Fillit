/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 02:46:37 by pdonnie           #+#    #+#             */
/*   Updated: 2019/08/02 12:09:56 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_box	*ft_new_list(char **p_tetr, t_box **p_list)
{
	t_box	*p_new_list;

	if ((p_new_list = malloc(sizeof(t_box))) == NULL)
		return (NULL);
	p_new_list->x = 0;
	p_new_list->y = 0;
	p_new_list->tetr = (*p_tetr);
	p_new_list->next = NULL;
	p_new_list->prev = *p_list;
	if (*p_list)
		(*p_list)->next = p_new_list;
	(*p_tetr) = NULL;
	return (p_new_list);
}

void	ft_red_coord(char *p, int i, int j)
{
	int		x;
	int		y;

	x = (int)(p[i++] - '0');
	y = (int)(p[i++] - '0');
	while (i != 8)
	{
		if (x > (int)(p[i] - '0'))
			x = (int)(p[i] - '0');
		i = i + 2;
	}
	while (++j != 8)
	{
		p[j] = (char)(((int)(p[j] - '0') - x) + '0');
		j++;
		p[j] = (char)(((int)(p[j] - '0') - y) + '0');
	}
}

char	*ft_search_coord(char **p_tetr, char *p_coord)
{
	int		i;
	int		j;
	char	x;
	char	y;

	i = -1;
	j = -1;
	x = 0;
	y = 0;
	while (y < 4)
	{
		while ((*p_tetr)[++i] != '#' && (*p_tetr)[i] != '\n')
			x++;
		if ((*p_tetr)[i] == '#')
		{
			p_coord[++j] = '0' + x++;
			p_coord[++j] = '0' + y;
		}
		if ((*p_tetr)[i] == '\n')
		{
			y++;
			x = 0;
		}
	}
	return (p_coord);
}

int		ft_get_x_y(char **p_tetr)
{
	char		*p_coord;
	static int	i;

	if ((p_coord = (char*)malloc(sizeof(char) * 10)) == NULL)
		return (-1);
	p_coord[9] = '\0';
	p_coord[8] = ('A' + i);
	p_coord = ft_search_coord((p_tetr), p_coord);
	free(*p_tetr);
	(*p_tetr) = p_coord;
	i++;
	return (0);
}

t_box	*ft_get_tetriminos(int fd, int r)
{
	char	*p;
	char	er;
	t_box	*p_l;

	p_l = NULL;
	while (r == 1 && (p = (char*)(malloc(sizeof(char) * 21)))
		&& (r = read(fd, p, 20)) > 0)
	{
		p[20] = '\0';
		if ((r = ft_check_file(p)) == -1 ||
				(r = ft_check_tetr(p)) == -1)
			return (NULL);
		if ((r = ft_get_x_y(&p)) == -1)
			return (NULL);
		ft_red_coord(p, 0, -1);
		er = '0';
		r = read(fd, &er, 1);
		if ((p_l = ft_new_list(&p, &p_l)) == NULL || (er != '\n' && er != '0'))
			return (NULL);
	}
	if ((!p && r < 0) || (r == 0 && !p_l) || er != '0')
		return (NULL);
	while (p_l->prev != NULL)
		p_l = p_l->prev;
	return (p_l);
}
