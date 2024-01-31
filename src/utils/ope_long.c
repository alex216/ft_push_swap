/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:13:04 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 19:45:48 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	return_minimum_step_of_push_insert(int ra, int rb, t_lst **stack_a,
		t_lst **stack_b)
{
	int	rra;
	int	rrb;
	int	minimum_of_four;

	rra = ft_dl_lstsize(*stack_a) - ra;
	rrb = ft_dl_lstsize(*stack_b) - rb;
	minimum_of_four = ft_four_min(ft_max(ra, rb), ft_max(rra, rrb), ra + rrb,
			rra + rb);
	return (minimum_of_four);
}

void	ope_long(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	t_lst	*iter_p;
	int		ra_num;
	int		rb_num;
	int		minimum;
	int		optimal_push_insert_node_index;
	int		temp;

	// operate_pb(stack_a, stack_b, lst_procedure);
	// operate_pb(stack_a, stack_b, lst_procedure);
	// operate_pb(stack_a, stack_b, lst_procedure);
	//
	// debug_func(stack_a, stack_b, lst_procedure, "a", "b", "lst");
	
	while (*stack_a)
	{
		iter_p = *stack_a;
		ra_num = 0;
		rb_num = 0;
		minimum = INT_MAX;
		optimal_push_insert_node_index = 0;
		while (iter_p->is_sentinel == false)
		{
			// rb_num = return_number_to_rotate_ascending(stack_b, iter_p);
			rb_num = return_number_to_rotate_descending(stack_b, iter_p);
			// ft_printf("rb num is %d\n", rb_num);
			// exit(42);
			temp = return_minimum_step_of_push_insert(ra_num, rb_num, stack_a, stack_b);
			if (temp < minimum)
			{
				minimum = temp;
				optimal_push_insert_node_index = ra_num;
			}
			ra_num++;
			iter_p = iter_p->next_p;
		}
		execute_optimized_push(minimum, optimal_push_insert_node_index, stack_a,
			stack_b, lst_procedure);
	}
	sort_stack_using_only_ra_or_rra_in_fastest_way_in_b(stack_b, lst_procedure);
	operate_rb(stack_a, stack_b, lst_procedure);
	// debug_func(stack_a, stack_b, lst_procedure, "a", "b", "lst");

	// while (*stack_b)
	// {
	// 	operate_rrb(stack_a, stack_b, lst_procedure);
	// 	operate_pa(stack_a, stack_b, lst_procedure);
	// }

	while (*stack_b)
		operate_pa(stack_a, stack_b, lst_procedure);
}
