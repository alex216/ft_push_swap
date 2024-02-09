/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_push_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:16:41 by yliu              #+#    #+#             */
/*   Updated: 2024/02/08 18:10:57 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_operate_ra_rb(t_node *node, t_game_lists *game_lists)
{
	int	ra;
	int	rb;
	int	ra_rb_min;

	ra = node->ra;
	rb = node->rb;
	ra_rb_min = ft_min(ra, rb);
	while (ra-- > ra_rb_min)
		operate_ra(game_lists);
	while (rb-- > ra_rb_min)
		operate_rb(game_lists);
	while (ra_rb_min--)
		operate_rr(game_lists);
}

// this can be ra then rrb or rrb then ra
static void	_operate_ra_rrb(t_node *node, t_game_lists *game_lists)
{
	int	ra;
	int	rrb;

	ra = node->ra;
	rrb = node->rrb;
	while (ra--)
		operate_ra(game_lists);
	ra++;
	while (rrb--)
		operate_rrb(game_lists);
}

// this can be rra then rb or rb then rra
static void	_operate_rra_rb(t_node *node, t_game_lists *game_lists)
{
	int	rra;
	int	rb;

	rra = node->rra;
	rb = node->rb;
	while (rra--)
		operate_rra(game_lists);
	rra++;
	while (rb--)
		operate_rb(game_lists);
}

static void	_operate_rra_rrb(t_node *node, t_game_lists *game_lists)
{
	int	rra;
	int	rrb;
	int	rra_rrb_min;

	rra = node->rra;
	rrb = node->rrb;
	rra_rrb_min = ft_min(rra, rrb);
	while (rra-- > rra_rrb_min)
		operate_rra(game_lists);
	while (rrb-- > rra_rrb_min)
		operate_rrb(game_lists);
	while (rra_rrb_min--)
		operate_rrr(game_lists);
}

void	rotate_both_stack_for_push(t_node *node_info, t_game_lists *game_lists)
{
	if (ft_max(node_info->ra, node_info->rb) == node_info->min_cost)
		_operate_ra_rb(node_info, game_lists);
	else if (node_info->ra + node_info->rrb == node_info->min_cost)
		_operate_ra_rrb(node_info, game_lists);
	else if (node_info->rra + node_info->rb == node_info->min_cost)
		_operate_rra_rb(node_info, game_lists);
	else if (ft_max(node_info->rra, node_info->rrb) == node_info->min_cost)
		_operate_rra_rrb(node_info, game_lists);
}
