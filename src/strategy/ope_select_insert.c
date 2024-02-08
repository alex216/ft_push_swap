/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_select_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:13:04 by yliu              #+#    #+#             */
/*   Updated: 2024/02/08 20:15:16 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_optimal_lst_p(t_node *node_info, t_lst **lst_pp,
			t_game_lists *game, void (*func)(t_lst *, t_node *, t_game_lists *))
{
	t_node	temp_node_info;
	int		temp_min_cost;
	t_lst	*iter_p;

	iter_p = *lst_pp;
	temp_min_cost = INT_MAX;
	while (iter_p->is_sentinel == false)
	{
		func(iter_p, &temp_node_info, game);
		if (temp_node_info.min_cost < temp_min_cost)
		{
			func(iter_p, node_info, game);
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
		return_optimal_lst_p(&node_info, &game->stack_a, game,
					   create_node_info_to_insert_to_b);
		rotate_both_stack_for_push(&node_info, game);
		operate_pb(game);
	}
	sort_stack_use_rb_rrb(&game->stack_b, game);
	while (game->stack_b)
		operate_pa(game);
}
