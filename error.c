/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 02:55:45 by pdonnie           #+#    #+#             */
/*   Updated: 2019/08/02 12:22:38 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(void)
{
	write(1, "error\n", 6);
	return (-1);
}

int		ft_wrong_argc(void)
{
	write(1, "usage: ./fillit one_file_with_tetriminos\n", 41);
	return (-1);
}

void	ft_clear_list(t_box **tetramino)
{
	t_box	*tmp;

	while (*tetramino != NULL)
	{
		free((*tetramino)->tetr);
		tmp = (*tetramino)->next;
		free(*tetramino);
		*tetramino = tmp;
	}
}

int		ft_change_list(t_box **p, short int *grid)
{
	(*p)->x = 0;
	(*p)->y = 0;
	if (((*p) = (*p)->prev) == NULL)
		return (0);
	ft_clean((*p), grid, 4);
	return (1);
}

int		ft_num_tetr(t_box *tetramino, int *side)
{
	int	i;

	i = 1;
	while (tetramino->next != NULL)
	{
		tetramino = tetramino->next;
		i++;
	}
	i = i * 4;
	*side = 2;
	while (i > (*side) * (*side))
		(*side)++;
	return (i);
}
