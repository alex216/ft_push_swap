/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:23:01 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 12:34:31 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	free_all(t_game_lists *game_lists)
{
	ft_dl_lstclear(&game_lists->stack_a, *del_push_swap);
	ft_dl_lstclear(&game_lists->stack_b, *del_push_swap);
	ft_dl_lstclear(&game_lists->lst_procedure, *del_push_swap);
}

int		g_count = 0;
void	debug_func(t_lst **a, t_lst **b, t_lst **tmp, char *q, char *w, char *e)
{
	g_count++;
	ft_printf("print is called [%d]\n", g_count);
	ft_printf("%s    ", q);
	ft_dl_pf_lst(*a, get_pointer_to_print);
	ft_printf("%s    ", w);
	ft_dl_pf_lst(*b, get_pointer_to_print);
	ft_printf("%s    ", e);
	ft_dl_pf_lst(*tmp, get_pointer_to_print);
}

void	print_index(t_lst **lst_pp)
{
	t_lst	*iter_p;

	iter_p = *lst_pp;
	while (iter_p->is_sentinel == false)
	{
		ft_printf("elem [%d] idx [%d]\n", get_int_value_of(iter_p),
			get_index_of(iter_p));
		iter_p = iter_p->next_p;
	}
}

int	handle_abnormal_input(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (255);
}
