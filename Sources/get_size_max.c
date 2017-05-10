/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 23:06:55 by proso             #+#    #+#             */
/*   Updated: 2017/05/09 23:06:57 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

int		get_size_max(t_list *begin_list)
{
	t_list	*current;
	int		size_max;

	size_max = 0;
	current = begin_list;
	while (current)
	{
		if (current->size > size_max)
			size_max = current->size;
		current = current->next;
	}
	return (size_max);
}
