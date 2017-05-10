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

int		default_terminal(t_select *info)
{
	tputs(tgetstr("ve", NULL), 1, ft_out);
	//tputs(tgetstr("te", NULL), 1, ft_out);
	if ((tcsetattr(0, TCSADRAIN, &info->d_term)) == -1)
		return (0);
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
	if ((tcsetattr(0, TCSADRAIN, &info->term)) == -1)
		return (0);
	return (1);
}
