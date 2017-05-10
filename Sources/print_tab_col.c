/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 21:22:31 by proso             #+#    #+#             */
/*   Updated: 2017/05/09 21:22:35 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

t_list	*print_col(int col_size, t_select *info, t_list *current)
{
	int		i;
	int		x;

	i = 0;
	x = info->curs_x;
	info->curs_y = 0;
	while (i < col_size && current)
	{
		ft_printf("%-*s", info->stock->size_max, current->data);
		current = current->next;
		i++;
		info->curs_y++;
		info->curs_x = x;
		CURSE_MOVE(info->curs_x, info->curs_y);
	}
	return (current);
}

int		init_var(t_select *info)
{
	if (!(info->stock = malloc(sizeof(t_stock))))
		return (0);
	info->stock->line_size = tgetnum("co");
	info->stock->size_max = get_size_max(info->data_list);
	info->col = 0;
	info->num_elem = 0;
	return (1);
}

void	print_list_col(t_select *info)
{
	t_list	*current;

	init_var(info);
	current = info->data_list;
	info->stock->elem_per_col = info->nb_elem /
							(info->stock->line_size / info->stock->size_max);
	if ((info->nb_elem % (info->stock->line_size / info->stock->size_max)))
		info->stock->elem_per_col++;
	while (current)
	{
		current = print_col(info->stock->elem_per_col, info, current);
		info->curs_x += (info->stock->size_max) + 1;
		info->curs_y = 0;
		CURSE_MOVE(info->curs_x, info->curs_y);
	}
}
