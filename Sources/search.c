/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 14:05:08 by proso             #+#    #+#             */
/*   Updated: 2017/05/25 14:05:10 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

void	show_search_mode(t_select *info)
{
	CURSE_MOVE(25, info->stock.y_max + 1);
	ft_dprintf(isatty(1), "{yellow}{bold}{underline}search :{res}  ");
	ft_dprintf(isatty(1), "{italic}%.*s{res}", info->stock.nb_ch - 35,
															info->buf_search);
	CURSE_MOVE(info->curs_x, info->curs_y);
}

int		write_buf_search(t_select *info)
{
	int		i;

	i = 0;
	while (info->buf_search[i])
		i++;
	if (i >= info->stock.nb_ch - 35)
		return (1);
	info->buf_search[i] = info->buf[0];
	return (1);
}

int		clear_buf_search(t_select *info)
{
	int		i;

	i = 0;
	while (info->buf_search[i])
		i++;
	if (i > 0)
		info->buf_search[i - 1] = '\0';
	return (1);
}

int		search_in_list(t_select *info)
{
	t_list	*current;
	int		i;

	current = ft_list_find(info->data_list, info->buf_search);
	if (!current)
		return (1);
	del_underline(info, info->num_elem);
	info->num_elem = get_num_elem(info, current);
	i = info->num_elem;
	if (info->num_elem < info->stock.nb_line)
		info->curs_y = i;
	else
		info->curs_y = i - (info->stock.nb_line * info->stock.nb_col);
	info->col = i / info->stock.nb_line;
	info->curs_x = (info->stock.size_max + 1) * info->col;
	next(info);
	return (1);
}
