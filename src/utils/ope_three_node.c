/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_three_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:43 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 16:32:07 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

ssize_t	ope_three_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)lst_procedure;
	(void)stack_b;

	int	first;
	int	second;
	int	third;

	first = get_int_value_of(*stack_a);
	second = get_int_value_of((*stack_a)->next_p);
	third = get_int_value_of((*stack_a)->next_p->next_p);
	if (first > second)
		if (first < third)
			if (second < third)
				operate_sa(stack_a, lst_procedure);
	if (first > second)
		if (first > third)
			if (second < third)
				operate_ra(stack_a, lst_procedure);
	if (first < second)
		if (first > third)
			if (second > third)
				operate_rra(stack_a, lst_procedure);
	if (first > second)	// 3 2 1
	{
		if (first > third)
		{
			if(second > third)
			{
				operate_sa(stack_a, lst_procedure);
				operate_rra(stack_a, lst_procedure);
			}
		}
	}
	if (first < second) // 1 3 2
	{
		if (first < third)
		{
			if(second > third)
			{
				operate_sa(stack_a, lst_procedure);
				operate_ra(stack_a, lst_procedure);
			}
		}
	}
	return (1);
}
