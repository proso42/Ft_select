/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:16:08 by proso             #+#    #+#             */
/*   Updated: 2017/05/10 15:16:09 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

int		space(t_select *info)
{
	t_list	*current;

	current = ft_get_p_elem(info->data_list, info->num_elem);
	current->slc = (current->slc) ? 0 : 1;
	CURSE_MOVE(info->curs_x, info->curs_y);
	if (current->slc)
		ft_dprintf(isatty(1), "{GREEN}{black}{underline}%s{GREEN}{res}%-*c",
				current->data, info->stock.size_max - current->size - 1, ' ');
	else
		ft_dprintf(isatty(1), "{res}{underline}{magenta}{bold}%s{res}%-*c",
				current->data, info->stock.size_max - current->size - 1, ' ');
	info->buf[0] = 27;
	info->buf[1] = 91;
	info->buf[2] = 66;
	return (arrow(info));
}

int		delete(t_select *info)
{
	int		i;
	int		num;

	num = info->num_elem;
	ft_push_back(&info->delete_list, ft_get_p_elem(info->data_list, num)->data);
	ft_clear_elem(&info->data_list, ft_get_p_elem(info->data_list, num));
	if (!info->data_list)
		return (0);
	i = info->stock.nb_line + 2;
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
