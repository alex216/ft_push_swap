/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_three_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:43 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 16:35:16 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static bool	_is_two_one_three(int first, int second, int third)
{
	return (second < first && first < third);
}

static bool	_is_one_three_two(int first, int second, int third)
{
	return (first < third && third < second);
}

static bool	_is_descending_order(int first, int second, int third)
{
	return (third < second && second < first);
}

void	append_sa_if_needed(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	int	first;
	int	second;
	int	third;

	if (is_ascending_order(*stack_a))
		return ;
	first = get_int_value_of(*stack_a);
	second = get_int_value_of((*stack_a)->next_p);
	third = get_int_value_of((*stack_a)->next_p->next_p);
	if (_is_two_one_three(first, second, third)
		|| _is_descending_order(first, second, third)
		|| _is_one_three_two(first, second, third))
		 operate_sa(stack_a, stack_b, lst_procedure);
}

void	ope_three_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	append_sa_if_needed(stack_a, stack_b, lst_procedure);
	sort_stack_using_only_ra_or_rra_in_fastest_way_in_a(stack_a, lst_procedure);
}
