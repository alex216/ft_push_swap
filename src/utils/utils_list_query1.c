/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_query1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:34:00 by yliu              #+#    #+#             */
/*   Updated: 2024/02/09 17:16:09 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_last_operation_is(const char *str, const t_lst **lst)
{
	char	*last_cmd;

	last_cmd = get_char_of(ft_dl_lstlast(*lst));
	return (!ft_strncmp(last_cmd, str, ft_strlen(str)));
}

static int	_return_min_cost_of_push_insert(t_node *node)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	mincost;

	ra = node->ra;
	rra = node->rra;
	rb = node->rb;
	rrb = node->rrb;
	mincost = ft_four_min(ft_max(ra, rb), ft_max(rra, rrb), ra + rrb, rra + rb);
	return (mincost);
}

void	create_node_info_to_insert_to_b(t_lst *iter_p, t_node *node,
			t_game_lists *game)
{
	node->ra = get_rotate_cost(&game->stack_a, iter_p);
	node->rb = return_num_to_descending(&game->stack_b, iter_p);
	node->rra = ft_dl_lstsize(game->stack_a) - node->ra;
	node->rrb = ft_dl_lstsize(game->stack_b) - node->rb;
	node->min_cost = _return_min_cost_of_push_insert(node);
}

void	create_node_info_to_insert_to_a(t_lst *iter_p, t_node *node,
			t_game_lists *game)
{
	node->rb = get_rotate_cost(&game->stack_b, iter_p);
	node->ra = return_num_to_ascending(&game->stack_a, iter_p);
	node->rra = ft_dl_lstsize(game->stack_a) - node->ra;
	node->rrb = ft_dl_lstsize(game->stack_b) - node->rb;
	node->min_cost = _return_min_cost_of_push_insert(node);
}
