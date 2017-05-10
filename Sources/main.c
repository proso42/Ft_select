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

void	unselect_all(t_select *info)
{
	t_list	*current;

	current = info->data_list;
	while (current)
	{
		current->slc = 0;
		current = current->next;
	}
}

int		main(int argc, char **argv)
{
	t_select	info;

	if (argc <= 1)
		return (0);
	if (!(init_terminal(&info)))
		return (-1);
	if (!(info.data_list = ft_tab_to_list(&argv[1])))
		return (-1);
	tputs(tgetstr("cl", NULL), 1, ft_out);
	info.nb_elem = ft_list_size(info.data_list);
	unselect_all(&info);
	print_list_col(&info);
	CURSE_MOVE(0, 0);
	tputs(tgetstr("vi", NULL), 1, ft_out);
	info.curs_x = 0;
	info.curs_y = 0;
	ft_printf("{underline}{bold}%s{res}%-*c", info.data_list->data,
							info.stock->size_max - info.data_list->size, ' ');
	while (1)
	{
//		ft_printf("%d | %d | %d\n", *info.buf, *(info.buf + 1), *(info.buf + 2));
		if (!(use_keyboard(&info)))
		{
			default_terminal(&info);
			return (0);
		}
		ft_memset(info.buf, 0, 3);
	}
	default_terminal(&info);
	return (0);
}
