/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_four_five_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:28 by yliu              #+#    #+#             */
/*   Updated: 2024/01/24 17:29:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static bool	_is_time_to_pa(t_lst **stack_a, t_lst **stack_b)
{
	int	a_top;
	int	a_tail;
	int	b_top;

	a_top = get_int_value_of(*stack_a);
	a_tail = get_int_value_of(ft_dl_lstlast(*stack_a));
	b_top = get_int_value_of(*stack_b);
	if (a_top < a_tail)
		return (b_top < a_top || b_top > a_tail);
	else
		return (a_tail < b_top && b_top < a_top);
}

static bool _put_node_to_right_pos(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	if (_is_time_to_pa(stack_a, stack_b))
		return (operate_pa(stack_a, stack_b, lst_procedure));
	operate_ra(stack_a, stack_b, lst_procedure);
	_put_node_to_right_pos(stack_a, stack_b, lst_procedure);
	operate_rra(stack_a, stack_b, lst_procedure);
	return (true);
}

void	ope_four_five_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	while (ft_dl_lstsize(*stack_a) > 3)
		operate_pb(stack_a, stack_b, lst_procedure);
	ope_three_node(stack_a, stack_b, lst_procedure);
	// debug_func(stack_a, stack_b, lst_procedure, "a", "b" ,"lst");

	_put_node_to_right_pos(stack_a, stack_b, lst_procedure);
	// debug_func(stack_a, stack_b, lst_procedure, "a", "b" ,"lst");

	while(!is_ascending_order(*stack_a))
		operate_ra(stack_a, stack_b, lst_procedure);
	// debug_func(stack_a, stack_b, lst_procedure, "a", "b" ,"lst");
}
