/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_three_four_five_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:28 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 17:47:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	_rotate_stack_fastly(t_lst **lst_pp, t_game_lists *lists, int ra)
{
	int	lst_size;

	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * ra < lst_size)
		while (ra--)
			operate_ra(lists);
	else
		while (lst_size - ra++)
			operate_rra(lists);
	return (true);
}

void	ope_three_four_five_node(t_game_lists *game_lists)
{
	int	ra;

	while (ft_dl_lstsize(game_lists->stack_a) > 3)
		operate_pb(game_lists);
	append_sa_if_needed(game_lists);
	while (game_lists->stack_b)
	{
		ra = return_num_to_ascending(&game_lists->stack_a, game_lists->stack_b);
		_rotate_stack_fastly(&game_lists->stack_a, game_lists, ra);
		operate_pa(game_lists);
	}
	sort_stack_use_ra_rra(&game_lists->stack_a, game_lists);
}
