/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_select_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:13:04 by yliu              #+#    #+#             */
/*   Updated: 2024/02/08 13:24:30 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst	*_return_optimal_lst_p(t_lst **stack_a, t_game_lists *game)
{
	t_node	temp_node_info;
	t_lst	*iter_p;
	int		temp_min_cost;
	t_lst	*optimal_lst_p;

	iter_p = *stack_a;
	temp_min_cost = INT_MAX;
	while (iter_p->is_sentinel == false)
	{
		create_node_info(iter_p, &temp_node_info, game);
		if (temp_node_info.min_cost < temp_min_cost)
		{
			optimal_lst_p = iter_p;
			temp_min_cost = temp_node_info.min_cost;
		}
		iter_p = iter_p->next_p;
	}
	return (optimal_lst_p);
}

void	ope_select_insert(t_game_lists *game)
{
	t_lst	*optimal_lst_p;

	while (game->stack_a)
	{
		optimal_lst_p = _return_optimal_lst_p(&game->stack_a, game);
		select_push_insert(optimal_lst_p, game);
	}
	sort_stack_use_rb_rrb(&game->stack_b, game);
	while (game->stack_b)
		operate_pa(game);
}
