/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:21 by yliu              #+#    #+#             */
/*   Updated: 2024/01/20 16:26:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	operate_sb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_a;
	if (!*stack_b)
		return ;
	operate_swap_top_and_second_top(stack_b);
	append_to_procedure(lst_procedure, "sb");
}

void	operate_rb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_a;
	if (!*stack_b)
		return ;
	operate_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rb");
}

void	operate_rrb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_a;
	if (!*stack_b)
		return ;
	operate_rev_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rrb");
}

void	operate_pb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if (!*stack_a)
		return ;
	if (!push_top_to_another_stack(stack_a, stack_b))
		exit(EXIT_FAILURE);
	append_to_procedure(lst_procedure, "pb");
}
