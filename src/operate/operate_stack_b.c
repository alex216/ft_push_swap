/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:21 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 14:25:33 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

bool	operate_sb(t_game_lists *game_lists)
{
	if (!game_lists->stack_b || ft_dl_lstsize(game_lists->stack_b) == 1)
		// || check_last_operation_is("sb", (const t_lst **)lst_procedure))
		return (false);
	operate_swap_top_and_second_top(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "sb");
	return (true);
}

bool	operate_rb(t_game_lists *game_lists)
{
	if (!game_lists->stack_b || ft_dl_lstsize(game_lists->stack_b) == 1)
		// || check_last_operation_is("rrb", (const t_lst **)lst_procedure))
		return (false);
	operate_rotate_top_and_tail(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "rb");
	return (true);
}

bool	operate_rrb(t_game_lists *game_lists)
{
	if (!game_lists->stack_b || ft_dl_lstsize(game_lists->stack_b) == 1)
		// || check_last_operation_is("rb", (const t_lst **)lst_procedure))
		return (false);
	operate_rev_rotate_top_and_tail(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "rrb");
	return (true);
}

bool	operate_pb(t_game_lists *game_lists)
{
	if (!game_lists->stack_a)
		// || check_last_operation_is("pa", (const t_lst **)lst_procedure))
		return (false);
	if (!operate_push_top_to_another_stack(&game_lists->stack_a, &game_lists->stack_b))
		exit(EXIT_FAILURE);
	append_to_procedure(&game_lists->lst_procedure, "pb");
	return (true);
}
