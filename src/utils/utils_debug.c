/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:23:01 by yliu              #+#    #+#             */
/*   Updated: 2024/02/02 16:38:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	debug_func(const t_game_lists *game)
{
	ft_dl_pf_lst(game->stack_a, get_pointer_to_print);
	ft_dl_pf_lst(game->stack_b, get_pointer_to_print);
	ft_dl_pf_lst(game->lst_procedure, get_pointer_to_print);
}

void	print_index(const t_lst **lst_pp)
{
	const t_lst	*iter_p;

	iter_p = *lst_pp;
	while (iter_p->is_sentinel == false)
	{
		ft_printf("elem [%d] idx [%d]\n", get_int_value_of(iter_p),
			get_index_of(iter_p));
		iter_p = iter_p->next_p;
	}
}
