/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:21 by yliu              #+#    #+#             */
/*   Updated: 2024/01/24 17:15:46 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

bool	operate_sb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_a;
	if (!*stack_b
		|| ft_dl_lstsize(*stack_b) == 1)
		// || check_last_operation_is("sb", (const t_lst **)lst_procedure))
		return (false);
	operate_swap_top_and_second_top(stack_b);
	append_to_procedure(lst_procedure, "sb");
	return (true);
}

bool	operate_rb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_a;
	if (!*stack_b
		|| ft_dl_lstsize(*stack_b) == 1)
		// || check_last_operation_is("rrb", (const t_lst **)lst_procedure))
		return (false);
	operate_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rb");
	return (true);
}

bool	operate_rrb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_a;
	if (!*stack_b
		|| ft_dl_lstsize(*stack_b) == 1)
		// || check_last_operation_is("rb", (const t_lst **)lst_procedure))
		return (false);
	operate_rev_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rrb");
	return (true);
}

bool	operate_pb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if (!*stack_a)
		// || check_last_operation_is("pa", (const t_lst **)lst_procedure))
		return (false);
	if (!push_top_to_another_stack(stack_a, stack_b))
		exit(EXIT_FAILURE);
	append_to_procedure(lst_procedure, "pb");
	return (true);
}
