/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:26:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/20 17:11:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	operate_sa(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_b;
	if (!*stack_a)
		return ;
	operate_swap_top_and_second_top(stack_a);
	append_to_procedure(lst_procedure, "sa");
}

void	operate_ra(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_b;
	if (!*stack_a)
		return ;
	operate_rotate_top_and_tail(stack_a);
	append_to_procedure(lst_procedure, "ra");
}

void	operate_rra(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_b;
	if (!*stack_a)
		return ;
	operate_rev_rotate_top_and_tail(stack_a);
	append_to_procedure(lst_procedure, "rra");
}

void	operate_pa(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if (!*stack_b)
		return ;
	if (!push_top_to_another_stack(stack_b, stack_a))
		exit(EXIT_FAILURE);
	append_to_procedure(lst_procedure, "pa");
}
