/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_both_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:35:51 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 13:22:22 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	operate_ss(t_game_lists *game_lists)
{
	int	a_size;
	int	b_size;

	a_size = ft_dl_lstsize(game_lists->stack_a);
	b_size = ft_dl_lstsize(game_lists->stack_b);
	if (a_size == 1 && b_size == 1)
		// || check_last_operation_is("ss", (const t_lst **)lst_procedure))
		return (false);
	if (!game_lists->stack_a || a_size == 1)
		return (operate_sb(game_lists));
	if (!game_lists->stack_b || b_size == 1)
		return (operate_sa(game_lists));
	operate_swap_top_and_second_top(&game_lists->stack_a);
	operate_swap_top_and_second_top(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "ss");
	return (true);
}

bool	operate_rr(t_game_lists *game_lists)
{
	int	a_size;
	int	b_size;

	a_size = ft_dl_lstsize(game_lists->stack_a);
	b_size = ft_dl_lstsize(game_lists->stack_b);
	// if(check_last_operation_is("rrr", (const t_lst **)lst_procedure))
	// 	return (false);
	if (!game_lists->stack_a || a_size == 1)
		return (operate_rb(game_lists));
	if (!game_lists->stack_b || b_size == 1)
		return (operate_ra(game_lists));
	operate_rotate_top_and_tail(&game_lists->stack_a);
	operate_rotate_top_and_tail(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "rr");
	return (true);
}

bool	operate_rrr(t_game_lists *game_lists)
{
	int	a_size;
	int	b_size;

	a_size = ft_dl_lstsize(game_lists->stack_a);
	b_size = ft_dl_lstsize(game_lists->stack_b);
	// if (check_last_operation_is("rr", (const t_lst **)lst_procedure))
	// 	return (false);
	if (!game_lists->stack_a || a_size == 1)
		return (operate_rrb(game_lists));
	if (!game_lists->stack_b || b_size == 1)
		return (operate_rra(game_lists));
	operate_rev_rotate_top_and_tail(&game_lists->stack_a);
	operate_rev_rotate_top_and_tail(&game_lists->stack_b);
	append_to_procedure(&game_lists->lst_procedure, "rrr");
	return (true);
}
