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

int		left_arrow(t_select *info)
{
	t_list	*current;
	int		rep;

	if (!(rep = test_go_up_rigth(info)))
	{
		current = ft_get_p_elem(info->data_list, info->num_elem);
		CURSE_MOVE(info->curs_x, info->curs_y);
		(current->slc) ? ft_printf("{INV}") : ft_printf("{res}");
		ft_printf("%-*s", info->stock->size_max, current->data);
		info->col--;
		info->num_elem -= info->stock->elem_per_col;
		info->curs_x = (info->stock->size_max + 1) * info->col;
	}
	else if (rep < 0)
		return (1);
	current = ft_get_p_elem(info->data_list, info->num_elem);
	CURSE_MOVE(info->curs_x, info->curs_y);
	(current->slc) ? ft_printf("{INV}") : ft_printf("{res}");
	ft_printf("{underline}{bold}%-*s{res}",
						info->stock->size_max - current->size, current->data);
	return (1);
}

int		rigth_arrow(t_select *info)
{
	t_list	*current;
	int		rep;

	if (!(rep = test_go_down_left(info)))
	{
		if (info->num_elem + info->stock->elem_per_col >= info->nb_elem)
			return (1);
		current = ft_get_p_elem(info->data_list, info->num_elem);
		CURSE_MOVE(info->curs_x, info->curs_y);
		(current->slc) ? ft_printf("{INV}") : ft_printf("{res}");
		ft_printf("%-*s", info->stock->size_max, current->data);
		info->col++;
		info->num_elem += info->stock->elem_per_col;
		info->curs_x = (info->stock->size_max + 1) * info->col;
	}
	else if (rep < 0)
		return (1);
	current = ft_get_p_elem(info->data_list, info->num_elem);
	CURSE_MOVE(info->curs_x, info->curs_y);
	(current->slc) ? ft_printf("{INV}") : ft_printf("{res}");
	ft_printf("{underline}{bold}%-*s{res}",
						info->stock->size_max - current->size, current->data);
	return (1);
}

int		up_arrow(t_select *info)
{
	t_list	*current;
	int		x;

	x = info->curs_x;
	current = ft_get_p_elem(info->data_list, info->num_elem);
	CURSE_MOVE(info->curs_x, info->curs_y);
	(current->slc) ? ft_printf("{INV}") : ft_printf("{res}");
	ft_printf("%-*s", info->stock->size_max, current->data);
	info->curs_x = x;
	info->curs_y--;
	info->num_elem--;
	if (info->num_elem < 0)
		reset_end(info);
	if (info->curs_y < 0)
	{
		info->curs_y = info->stock->elem_per_col - 1;
		info->col--;
		info->curs_x = (info->stock->size_max + 1) * info->col;
	}
	current = ft_get_p_elem(info->data_list, info->num_elem);
	CURSE_MOVE(info->curs_x, info->curs_y);
	(current->slc) ? ft_printf("{INV}") : ft_printf("{res}");
	ft_printf("{underline}{bold}%-*s{res}",
						info->stock->size_max - current->size, current->data);
	return (1);
}

int		down_arrow(t_select *info)
{
	t_list	*current;
	int		x;

	x = info->curs_x;
	current = ft_get_p_elem(info->data_list, info->num_elem);
	CURSE_MOVE(info->curs_x, info->curs_y);
	(current->slc) ? ft_printf("{INV}") : ft_printf("{res}");
	ft_printf("%-*s", info->stock->size_max, current->data);
	info->curs_x = x;
	info->curs_y++;
	info->num_elem++;
	if (info->num_elem >= info->nb_elem)
		reset_start(info);
	if (info->curs_y >= info->stock->elem_per_col)
	{
		info->curs_y = 0;
		info->col++;
		info->curs_x = (info->stock->size_max + 1) * info->col;
	}
	current = ft_get_p_elem(info->data_list, info->num_elem);
	CURSE_MOVE(info->curs_x, info->curs_y);
	(current->slc) ? ft_printf("{INV}") : ft_printf("{res}");
	ft_printf("{underline}{bold}%-*s{res}",
						info->stock->size_max - current->size, current->data);
	return (1);
}

int		arrow(t_select *info)
{
	if (info->buf[0] == 27 && info->buf[2] == 65)
		return (up_arrow(info));
	else if (info->buf[0] == 27 && info->buf[2] == 66)
		return (down_arrow(info));
	else if (info->buf[0] == 27 && info->buf[2] == 67)
		return (rigth_arrow(info));
	else if (info->buf[0] == 27 && info->buf[2] == 68)
		return (left_arrow(info));
	return (0);
}
