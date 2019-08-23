/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 02:53:36 by pdonnie           #+#    #+#             */
/*   Updated: 2019/07/31 14:40:57 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tetr(char *p)
{
	int		i;
	int		touch;

	i = -1;
	touch = 0;
	while (p[++i] != '\0')
	{
		while ((p[i] != '#' || p[i] == '\n') && p[i] != '\0')
			i++;
		if (p[i] != '\0' && i != 0 && p[i - 1] == '#')
			touch++;
		if (p[i] != '\0' && p[i + 1] == '#')
			touch++;
		if (p[i] != '\0' && (i - 5) >= 0 && p[i - 5] == '#')
			touch++;
		if (p[i] != '\0' && (i + 5) < 20 && p[i + 5] == '#')
			touch++;
	}
	return ((touch >= 6) ? 0 : -1);
}

int		ft_check_file(char *p)
{
	static int	nb_tetr;
	int			nb_sharp;
	int			i;
	int			block;

	if (nb_tetr > 25)
		return (-1);
	i = -1;
	nb_sharp = -1;
	while (p[++i] != '\0')
	{
		block = -1;
		while ((p[i] == '#' || p[i] == '.') &&
				++block < 4 && nb_sharp < 4)
			if (p[i++] == '#')
				nb_sharp++;
		if (block != 3 || p[i] != '\n')
			return (-1);
	}
	nb_tetr++;
	return (0);
}
