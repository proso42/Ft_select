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

int			ft_out(int c)
{
	write(0, &c, 1);
	return (1);
}

static void	loop(t_select *info)
{
	int		ret;

	info->delete_list = NULL;
	while (1)
	{
		if (!(ret = use_keyboard(info)))
		{
			default_terminal(info, 1);
			exit(0);
		}
		else if (ret < 0)
		{
			default_terminal(info, 0);
			exit(0);
		}
//	ft_printf("%d | %d | %d\n", *info->buf, *(info->buf + 1), *(info->buf + 2));
		ft_memset(info->buf, 0, 3);
		if (!info->small_screen)
		{
			show_nb_elem_slc(info);
			show_search_mode(info);
		}
	}
	default_terminal(info, 0);
}

int			main(int argc, char **argv)
{
	t_select	info;

	if (argc <= 1)
		return (0);
	if (!(init_terminal(&info)))
	{
		ft_dprintf(1, "{red}{bold}Missing some environment variable !{res}\n");
		return (-1);
	}
	if (!(info.data_list = ft_tab_to_list(&argv[1])))
		return (-1);
	info.nb_elem = ft_list_size(info.data_list);
	info.num_elem = 0;
	get_info(&info);
	init_signal();
	unselect_all(&info);
	if (print_list_col(&info))
	{
		ft_dprintf(isatty(1), "{underline}{bold}{cyan}%s{res}%-*c",
		info.data_list->data, info.stock.size_max - info.data_list->size, ' ');
		show_nb_elem_slc(&info);
		show_search_mode(&info);
	}
	loop(&info);
	return (0);
}
