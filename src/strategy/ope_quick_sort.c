/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:43:02 by yliu              #+#    #+#             */
/*   Updated: 2024/02/09 16:24:16 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stddef.h>

void	_divide(size_t width, t_game_lists *game)
{
	int		temp_size;
	size_t	pivot;

	pivot = width;
	while (game->stack_a)
	{
		temp_size = ft_dl_lstsize(game->stack_a);
		int i = 0;
		while (i < temp_size)
		{
			size_t pushing_index = get_index_of(game->stack_a);
			if (pushing_index <= pivot + width)
			{
				operate_pb(game);
				if (pushing_index <= pivot)
					operate_rb(game);
			}
			else
				operate_ra(game);
			i++;
		}
		pivot += 2 * width;
	}
}

void	ope_quick_sort(t_game_lists *game)
{
	t_node	node_info;
	size_t	divide_width;
	int		divided;
	int	min_index_can_move;

	divided = 10;
	divide_width = ft_dl_lstsize(game->stack_a) / divided;
	min_index_can_move = ft_dl_lstsize(game->stack_a) - divide_width;
	_divide(divide_width, game);
	size_t cnt = 0;
	while (game->stack_b)
	{
		return_optimal_lst_p(&node_info, &game->stack_b, game, min_index_can_move,
									   create_node_info_to_insert_to_a);
		rotate_both_stack_for_push(&node_info, game);
		operate_pa(game);
		cnt++;
		if (cnt >= divide_width)
		{
			min_index_can_move -= divide_width;
			cnt = 0;
		}
	}
	sort_stack_use_ra_rra(&game->stack_a, game);
}
