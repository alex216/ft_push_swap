/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:13:04 by yliu              #+#    #+#             */
/*   Updated: 2024/02/07 15:48:36 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	_return_min_cost_of_push_insert(t_node *node)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	min_cost;

	ra = node->ra;
	rra = node->rra;
	rb = node->rb;
	rrb = node->rrb;
	min_cost = ft_four_min(ft_max(ra, rb), ft_max(rra, rrb), ra + rrb, rra + rb);
	return (min_cost);
}

void	create_node_info_from_lst_p(t_lst *iter_p, t_node *node, t_game_lists *game)
{
	node->ra = get_ra_counter(&game->stack_a, iter_p);
	node->rra = ft_dl_lstsize(game->stack_a) - node->ra;
	node->rb = return_num_to_descending(&game->stack_b, iter_p);
	node->rrb = ft_dl_lstsize(game->stack_b) - node->rb;
	node->min_cost = _return_min_cost_of_push_insert(node);
}

// #ifdef DEBUF2
// #include <stdio.h>
// #endif
static t_lst	*_return_optimal_lst_p(t_lst **stack_a, t_game_lists *game)
{
	t_node	temp_node_info;
	t_lst	*iter_p;
	int		temp_min_cost;
	t_lst	*optimal_lst_p;

	iter_p = *stack_a;
	temp_min_cost = INT_MAX;
	// optimal_lst_p = NULL;
	// #ifdef DEBUG2
	// ft_printf("------size is [%d]\n", ft_dl_lstsize(*stack_a));
	// #endif
	while (iter_p->is_sentinel == false)
	{
		create_node_info_from_lst_p(iter_p, &temp_node_info, game);
		// temp -= get_min_cost_to_push(stack_a, iter_p);
		// #ifdef DEBUG2
		// ft_printf("%d[%d]", (int)get_index_of(iter_p), temp);
		// for (int i = 0; i < temp; i++)
		// 	ft_printf("#");
		// ft_printf("\n");
		// #endif
		if (temp_node_info.min_cost < temp_min_cost)
		{
			optimal_lst_p = iter_p;
			temp_min_cost = temp_node_info.min_cost;
		}
		iter_p = iter_p->next_p;
	}
	// #ifdef DEBUG2
	// ft_printf("gone node index is %d\n", optimal_push_insert_node_index);
	// #endif
	return (optimal_lst_p);
}

void	ope_long(t_game_lists *game)
{
	t_lst *optimal_node;

	while (game->stack_a)
	{
		optimal_node = _return_optimal_lst_p(&game->stack_a, game);
		execute_optimized_push(optimal_node, game);
	}
	sort_stack_use_rb_rrb(&game->stack_b, game);
	while (game->stack_b)
		operate_pa(game);
}
