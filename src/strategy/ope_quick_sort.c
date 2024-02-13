/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:43:02 by yliu              #+#    #+#             */
/*   Updated: 2024/02/12 13:48:55 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_return_optimal_lst_p(t_node *node_info, t_game_lists *game,
				int min_index_can_move)
{
	t_node	temp_node_info;
	int		temp_min_cost;
	t_lst	*iter_p;

	iter_p = game->stack_b;
	temp_min_cost = INT_MAX;
	while (iter_p->is_sentinel == false)
	{
		if ((int)get_index_of(iter_p) > min_index_can_move)
		{
			create_node_info_to_insert_to_a(iter_p, &temp_node_info, game);
			if (temp_node_info.min_cost < temp_min_cost)
			{
				create_node_info_to_insert_to_a(iter_p, node_info, game);
				temp_min_cost = temp_node_info.min_cost;
			}
		}
		iter_p = iter_p->next_p;
	}
}

static void	_exec_pb_or_ra(size_t pivot, size_t width, t_game_lists *game)
{
	size_t	pushing_index;

	pushing_index = get_index_of(game->stack_a);
	if (pushing_index <= pivot + width)
	{
		operate_pb(game);
		if (pushing_index <= pivot)
			operate_rb(game);
	}
	else
		operate_ra(game);
}

static void	_divide(size_t width, t_game_lists *game)
{
	int		stack_a_size;
	size_t	pivot;
	int		i;

	pivot = width;
	while (game->stack_a)
	{
		stack_a_size = ft_dl_lstsize(game->stack_a);
		i = 0;
		while (i < stack_a_size)
		{
			_exec_pb_or_ra(pivot, width, game);
			i++;
		}
		pivot += 2 * width;
	}
}

void	ope_quick_sort(t_game_lists *game)
{
	t_node	node_info;
	int		divide_width;
	int		divided_num;
	int		min_index_can_move;
	int		cnt;

	divided_num = 6;
	divide_width = ft_dl_lstsize(game->stack_a) / divided_num;
	min_index_can_move = ft_dl_lstsize(game->stack_a) - divide_width;
	_divide(divide_width, game);
	cnt = 0;
	while (game->stack_b)
	{
		_return_optimal_lst_p(&node_info, game, min_index_can_move);
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
