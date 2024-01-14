/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_three_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:43 by yliu              #+#    #+#             */
/*   Updated: 2024/01/14 20:38:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_two_one_three(int first, int second, int third)
{
	return (first > second && first < third && second < third);
}

static bool	is_three_one_two(int first, int second, int third)
{
	return (first > second && first > third && second < third);
}

static bool	is_two_three_one(int first, int second, int third)
{
	return (first < second && first > third && second > third);
}

static bool	is_descending_order(int first, int second, int third)
{
	return (first > second && second > third);
}

void	ope_three_node(t_lst **stack_a, t_lst **lst_procedure)
{
	(void)lst_procedure;

	int	first;
	int	second;
	int	third;

	first = get_int_value_of(*stack_a);
	second = get_int_value_of((*stack_a)->next_p);
	third = get_int_value_of((*stack_a)->next_p->next_p);
	if (is_two_one_three(first, second, third))
		return (operate_sa(stack_a, lst_procedure));
	else if (is_three_one_two(first, second, third))
		return (operate_ra(stack_a, lst_procedure));
	else if (is_two_three_one(first, second, third))
		return (operate_rra(stack_a, lst_procedure));
	operate_sa(stack_a, lst_procedure);
	if (is_descending_order(first, second, third))
		return (operate_rra(stack_a, lst_procedure));
	else
		return (operate_ra(stack_a, lst_procedure));
}
