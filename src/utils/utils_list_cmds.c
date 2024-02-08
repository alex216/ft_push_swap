/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:05 by yliu              #+#    #+#             */
/*   Updated: 2024/02/08 13:24:30 by yliu             ###   ########.fr       */
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

static int	_return_min_cost_of_push_insert(t_node *node)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	mincost;

	ra = node->ra;
	rra = node->rra;
	rb = node->rb;
	rrb = node->rrb;
	mincost = ft_four_min(ft_max(ra, rb), ft_max(rra, rrb), ra + rrb, rra + rb);
	return (mincost);
}

void	create_node_info(t_lst *iter_p, t_node *node, t_game_lists *game)
{
	node->ra = get_ra_counter(&game->stack_a, iter_p);
	node->rra = ft_dl_lstsize(game->stack_a) - node->ra;
	node->rb = return_num_to_descending(&game->stack_b, iter_p);
	node->rrb = ft_dl_lstsize(game->stack_b) - node->rb;
	node->min_cost = _return_min_cost_of_push_insert(node);
}
