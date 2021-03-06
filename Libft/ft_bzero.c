/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:05:50 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 20:23:19 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*chaine;
	size_t	i;

	i = 0;
	chaine = s;
	while (i < n)
	{
		chaine[i] = 0;
		i++;
	}
}
