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
	if (current->slc)
		ft_dprintf(0, "{GREEN}{black}{underline}%s{res}{GREEN}%-*c{res}",
				current->data, info->stock->size_max - current->size - 1, ' ');
	else
		ft_dprintf(0, "{res}{underline}{bold}%s{res}%-*c", current->data,
								info->stock->size_max - current->size - 1, ' ');
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

void	show_nb_elem_slc(t_select *info)
{
	int 	y;
	int		nb_elem_slc;
	t_list	*current;

	y = info->stock->elem_per_col + 2;
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
	ft_dprintf(0,
		"{yellow}{bold}{underline}%Clement(s) s%Cl%Cctionn%C(s) :{res} %d"
		, L'É', L'é', L'é', L'é', nb_elem_slc);
	CURSE_MOVE(info->curs_x, info->curs_y);
}
