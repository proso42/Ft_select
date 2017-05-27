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
# include <sys/ioctl.h>
# include "libft.h"

# define CURSE_MOVE(x, y) tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_out)

typedef struct			s_stock
{
	int					size_max;
	int					y_max;
	int					nb_line;
	int					nb_ch;
	int					nb_col;
}						t_stock;

typedef struct			s_select
{
		struct	termios	term;
		struct	termios	d_term;
		struct	s_stock	stock;
		char			*name_term;
		char			buf[3];
		t_list			*data_list;
		t_list			*delete_list;
		int				curs_x;
		int				curs_y;
		int				nb_elem;
		int				col;
		int				num_elem;
		int				all;
		char			buf_search[100];
		int				small_screen;
		int				nb_page;
		int				page;
}						t_select;

int			init_terminal(t_select *info);
int			default_terminal(t_select *info, int mode);
int			use_keyboard(t_select *info);
int			arrow(t_select *info);
int			ft_out(int c);
int			get_size_max(t_list *begin_list);
int			print_list_col(t_select *info);
void		reset_start(t_select *info);
void		reset_end(t_select *info);
int			test_go_up_rigth(t_select *info);
int			test_go_down_left(t_select *info);
int			space(t_select *info);
void		del_underline(t_select *info, int num);
void		next(t_select *info);
void		unselect_all(t_select *info);
int			select_all(t_select *info);
int			delete(t_select *info);
void		print_arg_slc(t_select *info);
void		show_nb_elem_slc(t_select *info);
t_select 	*get_info(t_select *info);
void		init_signal(void);
void		set_win(int sig);
void		show_search_mode(t_select *info);
int			write_buf_search(t_select *info);
int			clear_buf_search(t_select *info);
int			search_in_list(t_select *info);
int			get_num_elem(t_select *info, t_list *elem);
void		del_screen(t_select *info);
int			restore_elem(t_select *info);

#endif
