/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:43:02 by yliu              #+#    #+#             */
/*   Updated: 2024/02/08 18:57:03 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// void	_divide(int divide_width, t_game_lists *game)
// {
// 	int pivot_index;
//
//
// }
//

void	ope_quick_sort(t_game_lists *game)
{
	t_node	node_info;

	while (game->stack_a)
		operate_pb(game);
	while (game->stack_b)
	{
		return_optimal_lst_p(&node_info, &game->stack_b, game,
									   create_node_info_to_insert_to_a);
		rotate_both_stack_for_push(&node_info, game);
		operate_pa(game);
	}
	sort_stack_use_ra_rra(&game->stack_a, game);
// 	// int divide_width;
// 	//
// 	// divide_width = 50;
// 	while (game->stack_a)
// 		operate_pa(game);
// 	// _divide(divide_width, game);
// 	select_push_insert(t_lst *optimal_node, t_game_lists *game_lists)
}
