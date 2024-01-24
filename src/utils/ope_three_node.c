/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_three_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:43 by yliu              #+#    #+#             */
/*   Updated: 2024/01/24 16:52:25 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	_is_two_one_three(int first, int second, int third)
{
	return (first > second && first < third && second < third);
}

static bool	_is_three_one_two(int first, int second, int third)
{
	return (first > second && first > third && second < third);
}

static bool	_is_two_three_one(int first, int second, int third)
{
	return (first < second && first > third && second > third);
}

static bool	_is_descending_order(int first, int second, int third)
{
	return (first > second && second > third);
}

void	ope_three_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	(void)lst_procedure;

	int	first;
	int	second;
	int	third;

	if (is_ascending_order(*stack_a))
		return ;
	first = get_int_value_of(*stack_a);
	second = get_int_value_of((*stack_a)->next_p);
	third = get_int_value_of((*stack_a)->next_p->next_p);
	if (_is_two_one_three(first, second, third))
		 (operate_sa(stack_a, stack_b, lst_procedure));
	else if (_is_three_one_two(first, second, third))
		 (operate_ra(stack_a, stack_b, lst_procedure));
	else if (_is_two_three_one(first, second, third))
		 (operate_rra(stack_a, stack_b, lst_procedure));
	else
	{
		operate_sa(stack_a, stack_b, lst_procedure);
		if (_is_descending_order(first, second, third))
			operate_rra(stack_a, stack_b, lst_procedure);
		else
			operate_ra(stack_a, stack_b, lst_procedure);
	}
}
