/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 21:22:31 by proso             #+#    #+#             */
/*   Updated: 2017/05/09 21:22:35 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

static void	print_col(t_select *info)
{
	t_list	*current;

	current = ft_get_p_elem(info->data_list, info->num_elem);
	info->curs_y = 0;
	info->curs_x = info->col * (info->stock.size_max + 1);
	info->stock.nb_col++;
	CURSE_MOVE(info->curs_x, info->curs_y);
	while (info->curs_y < info->stock.nb_line && current)
	{
		if (current->slc)
			ft_dprintf(isatty(1), "{GREEN}{black}");
		else
			ft_dprintf(isatty(1), "{magenta}");
		ft_dprintf(isatty(1), "%-*s{res}", info->stock.size_max, current->data);
		info->curs_y++;
		info->num_elem++;
		CURSE_MOVE(info->curs_x, info->curs_y);
		current = current->next;
	}
	if (info->curs_y > info->stock.y_max)
		info->stock.y_max = info->curs_y;
}

void		del_screen(t_select *info)
{
	int		i;

	i = info->stock.y_max + 2;
	while (i >= 0)
	{
		CURSE_MOVE(0, i);
		tputs(tgetstr("dl", NULL), 0, ft_out);
		i--;
	}
}

static int	get_values(t_select *info)
{
	int				nb_elem_max;
	struct winsize	*sz;

	nb_elem_max = 0;
	if (!(sz = malloc(sizeof(struct winsize))))
		return (-1);
	ioctl(0, TIOCGWINSZ, sz);
	info->stock.nb_line = sz->ws_row - 2;
	info->stock.nb_ch = sz->ws_col;
	free(sz);
	info->stock.size_max = get_size_max(info->data_list);
	nb_elem_max = (info->stock.nb_ch / (info->stock.size_max + 1))
												* (info->stock.nb_line);
	if (nb_elem_max < info->nb_elem ||
							info->stock.nb_ch < info->stock.size_max + 34)
	{
		del_screen(info);
		CURSE_MOVE(0, 0);
		ft_dprintf(isatty(1), "{red}{bold}Screen too small...\n{res}");
		info->small_screen = 1;
		return (0);
	}
	return (1);
}

int			print_list_col(t_select *info)
{
	if (!(get_values(info)))
		return (0);
	info->small_screen = 0;
	info->stock.nb_col = -1;
	info->num_elem = 0;
	info->col = 0;
	info->stock.y_max = 0;
	while (info->num_elem < info->nb_elem)
	{
		print_col(info);
		info->col++;
	}
	info->curs_x = 0;
	info->curs_y = 0;
	info->col = 0;
	info->num_elem = 0;
	CURSE_MOVE(0, 0);
	return (1);
}
