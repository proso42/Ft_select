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

int		use_keyboard(t_select *info)
{
	read(0, info->buf, 3);
	if (info->buf[0] == 27 && info->buf[1] == 91 && info->buf[2])
		return (arrow(info));
	else if (info->buf[0] == 27 && !info->buf[1])
		return (0);
	else if (info->buf[0] == 32 && !info->buf[1])
		return (space(info));
	else if ((info->buf[0] == 127 || info->buf[0] == 126) && !info->buf[1])
		return (delete(info));
/*	{
		ft_printf("%d | %d | %d\n", info->buf[0], info->buf[1], info->buf[2]);
		return (1);
	}*/
	return (1);
}
