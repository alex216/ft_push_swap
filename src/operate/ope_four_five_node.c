/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_four_five_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:28 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 13:23:25 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static bool	_rotate_stack_in_shortest_way(t_lst **lst_pp, t_game_lists *game_lists, int ra_counter)
{
	int	lst_size;

	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * ra_counter < lst_size)
		while (ra_counter--)
			operate_ra(game_lists);
	else
		while (lst_size - ra_counter++)
			operate_rra(game_lists);
	return (true);
}

void	sort_stack_using_only_ra_or_rra_in_fastest_way_in_a(t_lst **lst_pp, t_game_lists *game_lists)
{
	int	top_idx;
	int	lst_size;

	top_idx = get_index_of(*lst_pp) - 1;
	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * top_idx < lst_size)
		while (top_idx--)
			operate_rra(game_lists);
	else
		while (lst_size - top_idx++)
			operate_ra(game_lists);
}

void	sort_stack_using_only_ra_or_rra_in_fastest_way_in_b(t_lst **lst_pp, t_game_lists *game_lists)
{
	int	top_idx;
	int	lst_size;

	top_idx = ft_dl_lstsize(*lst_pp) - get_index_of(*lst_pp);
	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * top_idx < lst_size)
		while (top_idx--)
			operate_rrb(game_lists);
	else
		while (lst_size - top_idx++)
			operate_rb(game_lists);
}

void	ope_four_five_node(t_game_lists *game_lists)
{
	int	ra;

	while (ft_dl_lstsize(game_lists->stack_a) > 3)
		operate_pb(game_lists);
	append_sa_if_needed(game_lists);
	while (game_lists->stack_b)
	{
		ra = return_number_to_rotate_ascending(&game_lists->stack_a, game_lists->stack_b);
		_rotate_stack_in_shortest_way(&game_lists->stack_a, game_lists, ra);
		operate_pa(game_lists);
	}
	sort_stack_using_only_ra_or_rra_in_fastest_way_in_a(&game_lists->stack_a, game_lists);
}
