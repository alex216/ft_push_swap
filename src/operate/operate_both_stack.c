/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_both_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:35:51 by yliu              #+#    #+#             */
/*   Updated: 2024/01/24 17:16:04 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	operate_ss(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);
bool	operate_rr(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);
bool	operate_rrr(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);

bool	operate_ss(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if ((ft_dl_lstsize(*stack_a) == 1 && ft_dl_lstsize(*stack_b) == 1))
		// || check_last_operation_is("ss", (const t_lst **)lst_procedure))
		return (false);
	if (!*stack_a || ft_dl_lstsize(*stack_a) == 1)
		return (operate_sb(stack_a, stack_b, lst_procedure));
	if (!*stack_b || ft_dl_lstsize(*stack_b) == 1)
		return (operate_sa(stack_a, stack_b, lst_procedure));
	operate_swap_top_and_second_top(stack_a);
	operate_swap_top_and_second_top(stack_b);
	append_to_procedure(lst_procedure, "ss");
	return (true);
}

bool	operate_rr(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	// if(check_last_operation_is("rrr", (const t_lst **)lst_procedure))
	// 	return (false);
	if (!*stack_a || ft_dl_lstsize(*stack_a) == 1)
		return (operate_rb(stack_a, stack_b, lst_procedure));
	if (!*stack_b || ft_dl_lstsize(*stack_b) == 1)
		return (operate_ra(stack_a, stack_b, lst_procedure));
	operate_rotate_top_and_tail(stack_a);
	operate_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rr");
	return (true);
}

bool	operate_rrr(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	// if (check_last_operation_is("rr", (const t_lst **)lst_procedure))
	// 	return (false);
	if (!*stack_a || ft_dl_lstsize(*stack_a) == 1)
		return (operate_rrb(stack_a, stack_b, lst_procedure));
	if (!*stack_b || ft_dl_lstsize(*stack_b) == 1)
		return (operate_rra(stack_a, stack_b, lst_procedure));
	operate_rev_rotate_top_and_tail(stack_a);
	operate_rev_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rrr");
	return (true);
}
