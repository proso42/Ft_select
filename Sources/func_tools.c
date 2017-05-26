/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:03:24 by proso             #+#    #+#             */
/*   Updated: 2017/05/09 13:03:26 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

void	del_underline(t_select *info, int num)
{
	t_list	*curr;

	curr = ft_get_p_elem(info->data_list, num);
	CURSE_MOVE(info->curs_x, info->curs_y);
	if (curr->slc)
		ft_dprintf(isatty(1), "{GREEN}{black}%-*s",
											info->stock.size_max, curr->data);
	else
		ft_dprintf(isatty(1), "{magenta}%-*s{res}",
											info->stock.size_max, curr->data);
}

int		test_go_up_rigth(t_select *info)
{
	int		tmp;

	if (info->col)
		return (0);
	tmp = info->num_elem;
	info->num_elem = ((info->stock.nb_line) * info->stock.nb_col) + tmp - 1;
	if (info->num_elem < 0 || info->num_elem >= info->nb_elem)
	{
		info->num_elem = tmp;
		return (-1);
	}
	del_underline(info, tmp);
	info->col = info->stock.nb_col;
	info->curs_x = (info->stock.size_max + 1) * info->col;
	info->curs_y--;
	return (1);
}

int		test_go_down_left(t_select *info)
{
	int		save;

	if (info->col == info->stock.nb_col)
	{
		save = info->num_elem;
		info->num_elem = info->curs_y + 1;
		if (info->num_elem < 0 || info->num_elem >= info->nb_elem)
		{
			info->num_elem = save;
			return (-1);
		}
		del_underline(info, save);
		info->col = 0;
		info->curs_x = 0;
		info->curs_y++;
		return (1);
	}
	return (0);
}

void	reset_start(t_select *info)
{
	info->num_elem = 0;
	info->curs_y = 0;
	info->curs_x = 0;
	info->col = 0;
}

void	reset_end(t_select *info)
{
	info->col = info->stock.nb_col;
	info->num_elem = info->nb_elem - 1;
	info->curs_x = (info->stock.size_max + 1) * info->col;
	if (info->stock.nb_col == 0)
		info->curs_y = info->num_elem;
	else
		info->curs_y = (info->nb_elem - 1) -
							(info->stock.nb_line * (info->stock.nb_col));
}
