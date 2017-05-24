/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:46:59 by proso             #+#    #+#             */
/*   Updated: 2017/05/05 10:47:01 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

int		ft_out(int c)
{
	write(1, &c, 1);
	return (1);
}

int		main(int argc, char **argv)
{
	t_select	info;

	if (argc <= 1)
		return (0);
	if (!(init_terminal(&info)))
	{
		ft_dprintf(0, "{red}{bold}Missing some environment variable !{res}\n");
		return (-1);
	}
	if (!(info.data_list = ft_tab_to_list(&argv[1])))
		return (-1);
	tputs(tgetstr("ti", NULL), 0, ft_out);
	tputs(tgetstr("vi", NULL), 0, ft_out);
	tputs(tgetstr("cl", NULL), 0, ft_out);
	info.nb_elem = ft_list_size(info.data_list);
	unselect_all(&info);
	print_list_col(&info);
	CURSE_MOVE(0, 0);
	info.curs_x = 0;
	info.curs_y = 0;
	ft_dprintf(0, "{underline}{bold}%s{res}%-*c", info.data_list->data,
							info.stock->size_max - info.data_list->size, ' ');
	show_nb_elem_slc(&info);
	while (1)
	{
//		ft_printf("%d | %d | %d\n", *info.buf, *(info.buf + 1), *(info.buf + 2));
		if (!(use_keyboard(&info)))
		{
			default_terminal(&info);
			return (0);
		}
		ft_memset(info.buf, 0, 3);
		show_nb_elem_slc(&info);
	}
	default_terminal(&info);
	return (0);
}
