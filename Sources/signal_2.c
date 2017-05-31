/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:33:16 by proso             #+#    #+#             */
/*   Updated: 2017/05/27 16:33:27 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

void		stop_win(int sig)
{
	t_select	*info;

	info = get_info(NULL);
	(void)sig;
	exit(default_terminal(info, 0));
}

void		ign_sig(int sig)
{
	(void)sig;
}
