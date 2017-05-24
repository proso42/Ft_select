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
	t_list	*current;

	current = ft_get_p_elem(info->data_list, num);
	CURSE_MOVE(info->curs_x, info->curs_y);
	if (current->slc)
		ft_dprintf(0, "{GREEN}{black}%-*s", info->stock->size_max, current->data);
	else
		ft_dprintf(0, "{res}%-*s", info->stock->size_max, current->data);
}

int		test_go_up_rigth(t_select *info)
{
	int		save;

	if (info->num_elem == 0)
		return (-1);
	else if (info->num_elem - info->stock->elem_per_col < 0)
	{
		save = info->num_elem;
		info->num_elem = save + ((info->stock->elem_per_col *
				((info->stock->line_size / info->stock->size_max) - 1))) - 1;
		if (info->num_elem < 0 || info->num_elem >= info->nb_elem)
		{
			info->num_elem = save;
			return (-1);
		}
		del_underline(info, save);
		info->col = (info->stock->line_size / info->stock->size_max) - 1;
		info->curs_x = (info->stock->size_max + 1) * info->col;
		info->curs_y--;
		return (1);
	}
	return (0);
}

int		test_go_down_left(t_select *info)
{
	int		save;

	if (info->col == (info->stock->line_size / info->stock->size_max) - 1)
	{
		save = info->num_elem;
		info->num_elem = save - ((info->stock->elem_per_col *
				((info->stock->line_size / info->stock->size_max) - 1))) + 1;
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
	int		i;
	int		j;

	i = 1;
	j = info->stock->elem_per_col;
	info->num_elem = info->nb_elem - 1;
	while (j && i++)
		if (j * i > info->nb_elem)
		{
			info->curs_y = info->nb_elem - (j * (i - 1)) - 1;
			j = 0;
		}
		else if (j * i == info->nb_elem)
		{
			info->curs_y = info->stock->elem_per_col - 1;
			j = 0;
		}
	info->col = (info->stock->line_size / info->stock->size_max) - 1;
	info->curs_x = (info->stock->size_max + 1) * (info->col);
}
