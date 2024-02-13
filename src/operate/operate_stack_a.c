/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:26:49 by yliu              #+#    #+#             */
/*   Updated: 2024/02/13 18:06:10 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	operate_sa(t_game_lists *game_lists)
{
	if (!game_lists->stack_a || ft_dl_lstsize(game_lists->stack_a) == 1)
		return (false);
	operate_swap_top_and_second_top(&game_lists->stack_a);
	append_to_procedure(&game_lists->lst_procedure, "sa");
	return (true);
}

bool	operate_ra(t_game_lists *game_lists)
{
	if (!game_lists->stack_a || ft_dl_lstsize(game_lists->stack_a) == 1)
		return (false);
	operate_rotate_top_and_tail(&game_lists->stack_a);
	append_to_procedure(&game_lists->lst_procedure, "ra");
	return (true);
}

bool	operate_rra(t_game_lists *game_lists)
{
	if (!game_lists->stack_a || ft_dl_lstsize(game_lists->stack_a) == 1)
		return (false);
	operate_rev_rotate_top_and_tail(&game_lists->stack_a);
	append_to_procedure(&game_lists->lst_procedure, "rra");
	return (true);
}

bool	operate_pa(t_game_lists *game_lists)
{
	t_lst	**stack_a_pp;
	t_lst	**stack_b_pp;

	stack_a_pp = &game_lists->stack_a;
	stack_b_pp = &game_lists->stack_b;
	if (!game_lists->stack_b)
		return (false);
	if (!operate_push_top_to_another_stack(stack_b_pp, stack_a_pp))
		exit(EXIT_FAILURE);
	append_to_procedure(&game_lists->lst_procedure, "pa");
	return (true);
}
