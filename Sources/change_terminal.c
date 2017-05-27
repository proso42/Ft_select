/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:07:28 by proso             #+#    #+#             */
/*   Updated: 2017/05/05 11:07:30 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

int		default_terminal(t_select *info, int mode)
{
	if ((tcsetattr(0, TCSADRAIN, &info->d_term)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 0, ft_out);
	tputs(tgetstr("ve", NULL), 0, ft_out);
	if (mode)
		print_arg_slc(info);
	return (1);
}

int		init_terminal(t_select *info)
{
	if (!(info->name_term = getenv("TERM")))
		return (0);
	if (!(tgetent(NULL, info->name_term)))
		return (0);
	if ((tcgetattr(0, &info->term)) == -1)
		return (0);
	if ((tcgetattr(0, &info->d_term)) == -1)
		return (0);
	info->term.c_lflag &= ~(ICANON);
	info->term.c_lflag &= ~(ECHO);
	info->term.c_cc[VMIN] = 1;
	info->term.c_cc[VTIME] = 0;
	info->curs_y = 0;
	info->curs_x = 0;
	info->all = 0;
	if ((tcsetattr(0, TCSADRAIN, &info->term)) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 0, ft_out);
	tputs(tgetstr("vi", NULL), 0, ft_out);
	tputs(tgetstr("cl", NULL), 0, ft_out);
	ft_bzero(info->buf_search, 100);
	ft_bzero(info->buf, 3);
	return (1);
}
