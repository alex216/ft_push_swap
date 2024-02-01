/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:13:04 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 13:55:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_return_minimum_step_of_push_insert(int ra, int rb, t_game_lists *game_lists)
{
	int	rra;
	int	rrb;
	int	minimum_of_four;

	rra = ft_dl_lstsize(game_lists->stack_a) - ra;
	rrb = ft_dl_lstsize(game_lists->stack_b) - rb;
	minimum_of_four = ft_four_min(ft_max(ra, rb), ft_max(rra, rrb), ra + rrb,
			rra + rb);
	return (minimum_of_four);
}

static int	_test(int *minimum, t_lst **stack_a, t_game_lists *game_lists)
{
	int		optimal_push_insert_node_index;
	t_lst	*iter_p;
	int		ra_num;
	int		rb_num;
	int		temp;

	iter_p = *stack_a;
	ra_num = 0;
	rb_num = 0;
	while (iter_p->is_sentinel == false)
	{
		rb_num = return_number_to_rotate_descending(&game_lists->stack_b, iter_p);
		temp = _return_minimum_step_of_push_insert(ra_num, rb_num, game_lists);
		if (temp < *minimum)
		{
			*minimum = temp;
			optimal_push_insert_node_index = ra_num;
		}
		ra_num++;
		iter_p = iter_p->next_p;
	}
	return (optimal_push_insert_node_index);
}

void	ope_long(t_game_lists *game_lists)
{
	int		minimum_step;
	int		optimal_node;

	while (game_lists->stack_a)
	{
		minimum_step = INT_MAX;
		optimal_node = _test(&minimum_step, &game_lists->stack_a, game_lists);
		execute_optimized_push(minimum_step, optimal_node, game_lists);
	}
	sort_stack_using_only_ra_or_rra_in_fastest_way_in_b(&game_lists->stack_b,
		game_lists);
	while (game_lists->stack_b)
		operate_pa(game_lists);
}
