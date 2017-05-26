/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_slc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:56:57 by proso             #+#    #+#             */
/*   Updated: 2017/05/15 15:56:59 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

void	print_arg_slc(t_select *info)
{
	t_list	*current;

	current = info->data_list;
	while (current)
	{
		if (current->slc)
		{
			ft_dprintf(1, " %s", current->data);
		}
		current = current->next;
	}
}
