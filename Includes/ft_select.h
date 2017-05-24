/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:47:45 by proso             #+#    #+#             */
/*   Updated: 2017/05/05 10:47:47 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <term.h>
#include <stdio.h>
# include "libft.h"

# define CURSE_MOVE(x, y) tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_out)

typedef struct			s_stock
{
	int					line_size;
	int					size_max;
	int					elem_per_col;
}						t_stock;

typedef struct			s_select
{
		struct	termios	term;
		struct	termios	d_term;
		struct	s_stock	*stock;
		char			*name_term;
		char			buf[3];
		t_list			*data_list;
		int				curs_x;
		int				curs_y;
		int				nb_elem;
		int				col;
		int				num_elem;
}						t_select;

int		init_terminal(t_select *info);
int		default_terminal(t_select *info);
int		use_keyboard(t_select *info);
int		arrow(t_select *info);
int		ft_out(int c);
void	delete_word(t_select *info, t_list *current);
int		get_size_max(t_list *begin_list);
void	print_list_col(t_select *info);
void	reset_start(t_select *info);
void	reset_end(t_select *info);
int		test_go_up_rigth(t_select *info);
int		test_go_down_left(t_select *info);
int		space(t_select *info);
void	del_underline(t_select *info, int num);
void	next(t_select *info);
void	unselect_all(t_select *info);
void	unselect_some(t_select *info);
int		delete(t_select *info);
void	print_arg_slc(t_select *info);
void	show_nb_elem_slc(t_select *info);

#endif
