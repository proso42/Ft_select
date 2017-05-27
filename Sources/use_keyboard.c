/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:47:52 by proso             #+#    #+#             */
/*   Updated: 2017/05/07 16:47:54 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

static int	is_letter(t_select *info)
{
	if (info->buf[0] >= 97 && info->buf[0] <= 123)
		return (1);
	if (info->buf[0] >= 65 && info->buf[0] <= 91)
		return (1);
	if (info->buf[0] == 46 || info->buf[0] == 47 || info->buf[0] == 95)
		return (1);
	return (0);
}

int			use_keyboard(t_select *info)
{
	if (info->small_screen)
		return (1);
	read(0, info->buf, 3);
	if (info->buf[0] == 27 && info->buf[1] == 91 && info->buf[2])
		return (arrow(info));
	else if ((info->buf[0] == 27 && !info->buf[1]))
		return (-1);
	else if ((info->buf[0] == 10 && !info->buf[1]))
		return (0);
	else if (info->buf[0] == 32 && !info->buf[1])
		return (space(info));
	else if ((info->buf[0] == 127 || info->buf[0] == 126) && !info->buf[1])
		return (delete(info));
	else if (info->buf[0] == 1 && !info->buf[1])
		return (select_all(info));
	else if (is_letter(info) && !info->buf[1])
		return (write_buf_search(info));
	else if (info->buf[0] == 45 && !info->buf[1])
		return (clear_buf_search(info));
	else if (info->buf[0] == 9 && !info->buf[1])
		return (search_in_list(info));
	else if (info->buf[0] == 43 && !info->buf[1])
		return (restore_elem(info));
	return (1);
}
