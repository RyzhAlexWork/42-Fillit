/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 03:14:16 by pdonnie           #+#    #+#             */
/*   Updated: 2019/08/02 13:38:53 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_box
{
	int				x;
	int				y;
	char			*tetr;
	struct s_box	*next;
	struct s_box	*prev;
}				t_box;

int				ft_check_tetr(char *p);
int				ft_check_file(char *p);
int				ft_error(void);
int				ft_wrong_argc(void);
int				ft_change_list(t_box **p, short int *grid);
int				ft_num_tetr(t_box *tetramino, int *side);
int				ft_clean(t_box *p, short int *grid, int num_sharp);
void			ft_print_grid(t_box *tetramino, int side);
void			ft_clear_list(t_box **tetramino);
t_box			*ft_get_tetriminos(int fd, int r);

#endif
