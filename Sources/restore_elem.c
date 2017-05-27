/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:21:44 by proso             #+#    #+#             */
/*   Updated: 2017/05/26 17:21:47 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

int		restore_elem(t_select *info)
{
	int		i;
	int		num;

	if (!info->delete_list)
		return (1);
	ft_push_back(&info->data_list, ft_list_last(info->delete_list)->data);
	ft_clear_elem(&info->delete_list, ft_list_last(info->delete_list));
	ft_list_last(info->data_list)->slc = 0;
	i = info->stock.nb_line + 2;
	num = info->num_elem;
	while (i >= 0)
	{
		CURSE_MOVE(0, i);
		tputs(tgetstr("dl", NULL), 0, ft_out);
		i--;
	}
	info->nb_elem = ft_list_size(info->data_list);
	print_list_col(info);
	info->num_elem = (num >= info->nb_elem) ? 0 : num;
	info->col = info->num_elem / (info->stock.nb_line);
	info->curs_x = (info->stock.size_max + 1) * info->col;
	info->curs_y = ABS(((info->stock.nb_line) * info->col) - info->num_elem);
	next(info);
	return (1);
}
