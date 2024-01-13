/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:21 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 21:33:36 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_sb(t_lst **stack_b, t_lst **lst_procedure)
{
	operate_swap_top_and_second_top(stack_b);
	append_to_procedure(lst_procedure, "sb");
}

void	operate_rb(t_lst **stack_b, t_lst **lst_procedure)
{
	operate_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rb");
}

void	operate_rrb(t_lst **stack_b, t_lst **lst_procedure)
{
	operate_rev_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rrb");
}

void	operate_pb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_a;
	(void)stack_b;
	(void)lst_procedure;
	// ft_dl_lst_insert_node_to_lst(*stack_a, stack_b);
	// ft_dl_lst_erase_node_from_lst(stack_a);
	// append_to_procedure(lst_procedure, "pb");
}
