/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:21 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 17:51:00 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

bool	operate_sb(t_game_lists *game_lists)
{
	if (!game_lists->stack_b || ft_dl_lstsize(game_lists->stack_b) == 1)
		return (false);
	operate_swap_top_and_second_top(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "sb");
	return (true);
}

bool	operate_rb(t_game_lists *game_lists)
{
	if (!game_lists->stack_b || ft_dl_lstsize(game_lists->stack_b) == 1)
		return (false);
	operate_rotate_top_and_tail(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "rb");
	return (true);
}

bool	operate_rrb(t_game_lists *game_lists)
{
	if (!game_lists->stack_b || ft_dl_lstsize(game_lists->stack_b) == 1)
		return (false);
	operate_rev_rotate_top_and_tail(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "rrb");
	return (true);
}

bool	operate_pb(t_game_lists *game_lists)
{
	t_lst	**stack_a_pp;
	t_lst	**stack_b_pp;

	stack_a_pp = &game_lists->stack_a;
	stack_b_pp = &game_lists->stack_b;
	if (!game_lists->stack_a)
		return (false);
	if (!operate_push_top_to_another_stack(stack_a_pp, stack_b_pp))
		exit(EXIT_FAILURE);
	append_to_procedure(&game_lists->lst_procedure, "pb");
	return (true);
}
