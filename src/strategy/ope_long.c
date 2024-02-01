/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:13:04 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 17:46:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_return_min_step_of_push_insert(int ra, int rb, t_game_lists *game)
{
	int	rra;
	int	rrb;
	int	min_of_four;

	rra = ft_dl_lstsize(game->stack_a) - ra;
	rrb = ft_dl_lstsize(game->stack_b) - rb;
	min_of_four = ft_four_min(ft_max(ra, rb), ft_max(rra, rrb), ra + rrb,
			rra + rb);
	return (min_of_four);
}

static int	_return_optimal_node(int *min, t_lst **stack_a, t_game_lists *game)
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
		rb_num = return_num_to_descending(&game->stack_b, iter_p);
		temp = _return_min_step_of_push_insert(ra_num, rb_num, game);
		if (temp < *min)
		{
			*min = temp;
			optimal_push_insert_node_index = ra_num;
		}
		ra_num++;
		iter_p = iter_p->next_p;
	}
	return (optimal_push_insert_node_index);
}

void	ope_long(t_game_lists *game)
{
	int		min_step;
	int		optimal_node;

	while (game->stack_a)
	{
		min_step = INT_MAX;
		optimal_node = _return_optimal_node(&min_step, &game->stack_a, game);
		execute_optimized_push(min_step, optimal_node, game);
	}
	sort_stack_use_rb_rrb(&game->stack_b,
		game);
	while (game->stack_b)
		operate_pa(game);
}
