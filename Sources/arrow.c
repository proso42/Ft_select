/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:54:02 by proso             #+#    #+#             */
/*   Updated: 2017/05/07 16:54:05 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

static int		left_arrow(t_select *info)
{
	int		rep;

	if (!info->num_elem)
		return (1);
	if (!(rep = test_go_up_rigth(info)))
	{
		del_underline(info, info->num_elem);
		info->col--;
		info->num_elem -= info->stock.nb_line;
		info->curs_x = (info->stock.size_max + 1) * info->col;
	}
	else if (rep < 0)
		return (1);
	next(info);
	return (1);
}

static int		rigth_arrow(t_select *info)
{
	int		rep;

	if (info->nb_elem == 1 && !info->num_elem)
		return (1);
	if (!(rep = test_go_down_left(info)))
	{
		if (info->num_elem + info->stock.nb_line >= info->nb_elem)
			return (1);
		del_underline(info, info->num_elem);
		info->col++;
		info->num_elem += info->stock.nb_line;
		info->curs_x = (info->stock.size_max + 1) * info->col;
	}
	else if (rep < 0)
		return (1);
	next(info);
	return (1);
}

static int		up_arrow(t_select *info)
{
	del_underline(info, info->num_elem);
	info->curs_y--;
	info->num_elem--;
	if (info->num_elem < 0)
		reset_end(info);
	if (info->curs_y < 0)
	{
		info->curs_y = info->stock.nb_line - 1;
		info->col--;
		info->curs_x = (info->stock.size_max + 1) * info->col;
	}
	next(info);
	return (1);
}

static int		down_arrow(t_select *info)
{
	del_underline(info, info->num_elem);
	info->curs_y++;
	info->num_elem++;
	if (info->num_elem >= info->nb_elem)
		reset_start(info);
	if (info->curs_y >= info->stock.nb_line)
	{
		info->curs_y = 0;
		info->col++;
		info->curs_x = (info->stock.size_max + 1) * info->col;
	}
	next(info);
	return (1);
}

int				arrow(t_select *info)
{
	if (info->buf[0] == 27 && info->buf[2] == 65 && info->nb_elem > 1)
		return (up_arrow(info));
	else if (info->buf[0] == 27 && info->buf[2] == 66 && info->nb_elem > 1)
		return (down_arrow(info));
	else if (info->buf[0] == 27 && info->buf[2] == 67 && info->nb_elem > 1)
		return (rigth_arrow(info));
	else if (info->buf[0] == 27 && info->buf[2] == 68 && info->nb_elem > 1)
		return (left_arrow(info));
	return (1);
}
