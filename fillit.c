/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <pdonnie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:31:11 by pdonnie           #+#    #+#             */
/*   Updated: 2019/08/02 13:39:18 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_clean(t_box *p, short int *grid, int num_sharp)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (num_sharp > 0)
	{
		x = (p->x) + (int)(p->tetr[i] - '0');
		y = (p->y) + (int)(p->tetr[i + 1] - '0');
		grid[y] = grid[y] & ~(1 << x);
		i = i + 2;
		num_sharp--;
	}
	return (-1);
}

int		ft_algorithm(t_box *p, short int *grid, int side, int *i)
{
	int	x;
	int	y;
	int	num_sharp;

	num_sharp = 0;
	while ((*i) < 8)
	{
		x = (p->x) + (int)(p->tetr[*i] - '0');
		y = (p->y) + (int)(p->tetr[*i + 1] - '0');
		if (x >= side || y >= side)
			return (ft_clean(p, grid, num_sharp));
		if (grid[y] & (1 << x))
			return (ft_clean(p, grid, num_sharp));
		grid[y] = grid[y] | (1 << x);
		num_sharp++;
		*i = *i + 2;
	}
	return (0);
}

int		ft_search_square(t_box *p, short int *grid, int side)
{
	int	i;
	int	status;

	while (p != NULL)
	{
		status = 0;
		i = 0;
		status = ft_algorithm(p, grid, side, &i);
		if (status != -1)
			p = p->next;
		else
		{
			if (((p->x) + (int)(p->tetr[i] - '0')) >= side)
			{
				p->x = -1;
				(p->y)++;
			}
			if (((p->y) + (int)(p->tetr[i + 1] - '0')) >= side)
				if ((status = ft_change_list(&p, grid)) == 0)
					return (0);
			(p->x)++;
		}
	}
	return (1);
}

void	ft_start(t_box *tetramino, int *side)
{
	int			status;
	short int	*grid;

	status = 0;
	if ((grid = (short int *)malloc(sizeof(short int) * 16)) == NULL)
		exit(-1);
	while (status == 0)
	{
		status = ft_search_square(tetramino, grid, (*side));
		(*side)++;
	}
	free(grid);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		side;
	int		i;
	t_box	*tetramino;

	if (argc != 2)
		return (ft_wrong_argc());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	if ((tetramino = ft_get_tetriminos(fd, 1)) == NULL)
		exit(ft_error());
	close(fd);
	i = ft_num_tetr(tetramino, &side);
	ft_start(tetramino, &side);
	ft_print_grid(tetramino, --side);
	ft_clear_list(&tetramino);
	return (0);
}
