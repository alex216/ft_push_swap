/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_both_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:35:51 by yliu              #+#    #+#             */
/*   Updated: 2024/01/19 21:01:17 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_ss(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if (!*stack_a || !*stack_b)
		return ;
	operate_swap_top_and_second_top(stack_a);
	operate_swap_top_and_second_top(stack_b);
	append_to_procedure(lst_procedure, "ss");
}

void	operate_rr(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if (!*stack_a || !*stack_b)
		return ;
	operate_rotate_top_and_tail(stack_a);
	operate_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rr");
}

void	operate_rrr(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if (!*stack_a || !*stack_b)
		return ;
	operate_rev_rotate_top_and_tail(stack_a);
	operate_rev_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rrr");
}
