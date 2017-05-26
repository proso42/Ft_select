/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:22:46 by proso             #+#    #+#             */
/*   Updated: 2017/05/24 18:22:48 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

t_select		*get_info(t_select *info)
{
	static t_select *p = NULL;

	if (!p)
		p = info;
	return (p);
}

void			set_win(int sig)
{
	t_select	*info;
	int			i;

	(void)sig;
	info = get_info(NULL);
	del_screen(info);
	i = info->num_elem;
	print_list_col(info);
	if (!info->small_screen)
	{
		show_nb_elem_slc(info);
		info->num_elem = i;
		if (info->num_elem < info->stock.nb_line)
			info->curs_y = info->num_elem;
		else
			info->curs_y = i - (info->stock.nb_line * info->stock.nb_col);
		info->col = i / info->stock.nb_line;
		info->curs_x = (info->stock.size_max + 1) * info->col;
		next(info);
		show_search_mode(info);
	}
}

static void		susp_win(int sig)
{
	t_select *info;

	info = get_info(NULL);
	default_terminal(info, 0);
	if (sig == 2)
		exit(0);
}

static void		end_susp(int sig)
{
	t_select	*info;
	char		save_buf_search[100];

	info = get_info(NULL);
	ft_strcpy(save_buf_search, info->buf_search);
	init_terminal(info);
	ft_strcpy(info->buf_search, save_buf_search);
	set_win(sig);
}

void			init_signal(void)
{
	signal(SIGWINCH, set_win);
	signal(SIGTSTP, susp_win);
	signal(SIGINT, susp_win);
	signal(SIGCONT, end_susp);
}
