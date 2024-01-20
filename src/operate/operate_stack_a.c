/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:26:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/20 19:58:33 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

bool	operate_sa(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_b;
	if (!*stack_a || ft_dl_lstsize(*stack_a) == 1)
		return (false);
	operate_swap_top_and_second_top(stack_a);
	append_to_procedure(lst_procedure, "sa");
	return (true);
}

bool	operate_ra(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_b;
	if (!*stack_a || ft_dl_lstsize(*stack_a) == 1)
		return (false);
	operate_rotate_top_and_tail(stack_a);
	append_to_procedure(lst_procedure, "ra");
	return (true);
}

bool	operate_rra(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)stack_b;
	if (!*stack_a || ft_dl_lstsize(*stack_a) == 1)
		return (false);
	operate_rev_rotate_top_and_tail(stack_a);
	append_to_procedure(lst_procedure, "rra");
	return (true);
}

bool	operate_pa(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if (!*stack_b)
		return (false);
	if (!push_top_to_another_stack(stack_b, stack_a))
		exit(EXIT_FAILURE);
	append_to_procedure(lst_procedure, "pa");
	return (true);
}
