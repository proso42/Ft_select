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
		ft_printf("{INV}{underline}{bold}%s{res}%-*c",
					current->data, info->stock->size_max - current->size, ' ');
	else
	ft_printf("{res}{underline}{bold}%s{res}%-*c",
				current->data, info->stock->size_max - current->size, ' ');
	info->buf[0] = 27;
	info->buf[1] = 91;
	info->buf[2] = 66;
	return (arrow(info));
}
