/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_select_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:13:04 by yliu              #+#    #+#             */
/*   Updated: 2024/02/09 17:12:58 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_return_optimal_lst_p(t_node *node_info, t_game_lists *game)
{
	t_node	temp_node_info;
	int		temp_min_cost;
	t_lst	*iter_p;

	iter_p = game->stack_a;
	temp_min_cost = INT_MAX;
	while (iter_p->is_sentinel == false)
	{
		create_node_info_to_insert_to_b(iter_p, &temp_node_info, game);
		if (temp_node_info.min_cost < temp_min_cost)
		{
			create_node_info_to_insert_to_b(iter_p, node_info, game);
			temp_min_cost = temp_node_info.min_cost;
		}
		iter_p = iter_p->next_p;
	}
}

void	ope_select_insert(t_game_lists *game)
{
	t_node	node_info;

	while (game->stack_a)
	{
		_return_optimal_lst_p(&node_info, game);
		rotate_both_stack_for_push(&node_info, game);
		operate_pb(game);
	}
	sort_stack_use_rb_rrb(&game->stack_b, game);
	while (game->stack_b)
		operate_pa(game);
}
