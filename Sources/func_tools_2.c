/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_tools_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:49:51 by proso             #+#    #+#             */
/*   Updated: 2017/05/14 14:49:54 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

void	next(t_select *info)
{
	t_list	*current;

	current = ft_get_p_elem(info->data_list, info->num_elem);
	CURSE_MOVE(info->curs_x, info->curs_y);
	if (current->slc && current->size < info->stock.size_max)
		ft_dprintf(isatty(1), "{GREEN}{black}{underline}%s{res}{GREEN}%-*c{res}"
				, current->data, info->stock.size_max - current->size - 1, ' ');
	else if (current->slc)
		ft_dprintf(isatty(1), "{GREEN}{black}{underline}%s{res}"
															, current->data);
	else
		ft_dprintf(isatty(1), "{res}{cyan}{underline}{bold}%s{res}%-*c"
				, current->data, info->stock.size_max - current->size - 1, ' ');
}

void	unselect_all(t_select *info)
{
	t_list	*current;
	int		i;

	i = 0;
	current = info->data_list;
	while (current)
	{
		current->slc = 0;
		current = current->next;
	}
}

int		select_all(t_select *info)
{
	t_list	*current;
	int		i;

	i = 0;
	current = info->data_list;
	while (current)
	{
		current->slc = (info->all) ? 0 : 1;
		current = current->next;
	}
	set_win(0);
	info->all = (info->all) ? 0 : 1;
	return (1);
}

void	show_nb_elem_slc(t_select *info)
{
	int		y;
	int		nb_elem_slc;
	t_list	*current;

	y = info->stock.y_max + 1;
	current = info->data_list;
	nb_elem_slc = 0;
	while (current)
	{
		nb_elem_slc += (current->slc) ? 1 : 0;
		current = current->next;
	}
	CURSE_MOVE(0, y);
	tputs(tgetstr("dl", NULL), 0, ft_out);
	CURSE_MOVE(0, y);
	ft_dprintf(isatty(1), "{yellow}{bold}{underline}Selected elements :{res} ");
	(nb_elem_slc) ? ft_dprintf(isatty(1), "{green}{bold}%d{res}", nb_elem_slc) :
					ft_dprintf(isatty(1), "{red}{bold}%d{res}", nb_elem_slc);
	CURSE_MOVE(info->curs_x, info->curs_y);
	info->all = (nb_elem_slc == info->nb_elem) ? 1 : 0;
}

int		get_num_elem(t_select *info, t_list *elem)
{
	int		i;
	t_list	*current;

	i = 0;
	current = info->data_list;
	while (current != elem && current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
