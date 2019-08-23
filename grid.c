/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 02:40:11 by pdonnie           #+#    #+#             */
/*   Updated: 2019/08/02 13:40:50 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_print_grid3(t_box *p, int side, char *grid, int i)
{
	int	index;

	index = p->x + (p->tetr[i] - '0') +
		(p->y + (p->tetr[i + 1] - '0')) * side;
	grid[index] = p->tetr[8];
	i = i + 2;
	return (i);
}

void	ft_print_grid2(t_box *p, int side, char *grid, int i)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (p != NULL)
	{
		i = 0;
		while (i < 8)
			i = ft_print_grid3(p, side, grid, i);
		p = p->next;
	}
	i = 0;
	while (grid[i] != '\0')
	{
		write(1, &grid[i], 1);
		if (i != 0 && ((i + 1) % side) == 0)
			write(1, "\n", 1);
		i++;
	}
}

void	ft_print_grid(t_box *p, int side)
{
	int		i;
	char	*grid;
	int		square;

	square = side * side;
	if ((grid = (char*)malloc(sizeof(char) * (square + 1))) == NULL)
		exit(-1);
	grid[square] = '\0';
	i = 0;
	while (square - i > 0)
	{
		grid[i] = '.';
		i++;
	}
	ft_print_grid2(p, side, grid, 0);
	free(grid);
}
