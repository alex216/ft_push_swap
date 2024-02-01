/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:16:41 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 13:01:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	_operate_ra_rb(int ra, int rb, t_game_lists *game_lists)
{
	int	ra_rb_min;

	ra_rb_min = ft_min(ra, rb);
	while (ra-- > ra_rb_min)
		operate_ra(game_lists);
	while (rb-- > ra_rb_min)
		operate_rb(game_lists);
	while (ra_rb_min--)
		operate_rr(game_lists);
	operate_pb(game_lists);
}

// this can be ra then rrb or rrb then ra
static void	_operate_ra_rrb(int ra, int rb, t_game_lists *game_lists)
{
	int	rrb;

	rrb = ft_dl_lstsize(game_lists->stack_b) - rb;
	while (ra--)
		operate_ra(game_lists);
	ra++;
	while (rrb--)
		operate_rrb(game_lists);
	operate_pb(game_lists);
}

// this can be rra then rb or rb then rra
static void	_operate_rra_rb(int ra, int rb, t_game_lists *game_lists)
{
	int	rra;

	rra = ft_dl_lstsize(game_lists->stack_a) - ra;
	while (rra--)
		operate_rra(game_lists);
	rra++;
	while (rb--)
		operate_rb(game_lists);
	operate_pb(game_lists);
}

static void	_operate_rra_rrb(int ra, int rb, t_game_lists *game_lists)
{
	int	rra;
	int	rrb;
	int	rra_rrb_min;

	rra = ft_dl_lstsize(game_lists->stack_a) - ra;
	rrb = ft_dl_lstsize(game_lists->stack_b) - rb;
	rra_rrb_min = ft_min(rra, rrb);
	while (rra-- > rra_rrb_min)
		operate_rra(game_lists);
	while (rrb-- > rra_rrb_min)
		operate_rrb(game_lists);
	while (rra_rrb_min--)
		operate_rrr(game_lists);
	operate_pb(game_lists);
}

void	execute_optimized_push(int minimum, int ra, t_game_lists *game_lists)
{
	int		temp_index;
	int		rb;
	int		rra;
	int		rrb;
	t_lst	*iter_p;

	temp_index = ra;
	iter_p = game_lists->stack_a;
	while (temp_index--)
		iter_p = iter_p->next_p;
	rra = ft_dl_lstsize(game_lists->stack_a) - ra;
	rb = return_number_to_rotate_descending(&game_lists->stack_b, iter_p);
	rrb = ft_dl_lstsize(game_lists->stack_b) - rb;
	if (ft_max(ra, rb) == minimum)
		_operate_ra_rb(ra, rb, game_lists);
	else if (ra + rrb == minimum)
		_operate_ra_rrb(ra, rb, game_lists);
	else if (rra + rb == minimum)
		_operate_rra_rb(ra, rb, game_lists);
	else if (ft_max(rra, rrb) == minimum)
		_operate_rra_rrb(ra, rb, game_lists);
}
