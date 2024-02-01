/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:05 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 17:17:55 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_use_ra_rra(t_lst **lst_pp, t_game_lists *game_lists)
{
	int	top_idx;
	int	lst_size;

	top_idx = get_index_of(*lst_pp) - 1;
	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * top_idx < lst_size)
		while (top_idx--)
			operate_rra(game_lists);
	else
		while (lst_size - top_idx++)
			operate_ra(game_lists);
}

void	sort_stack_use_rb_rrb(t_lst **lst_pp, t_game_lists *game_lists)
{
	int	top_idx;
	int	lst_size;

	top_idx = ft_dl_lstsize(*lst_pp) - get_index_of(*lst_pp);
	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * top_idx < lst_size)
		while (top_idx--)
			operate_rrb(game_lists);
	else
		while (lst_size - top_idx++)
			operate_rb(game_lists);
}
