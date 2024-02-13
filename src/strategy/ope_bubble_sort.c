/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_bubble_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:15:17 by yliu              #+#    #+#             */
/*   Updated: 2024/02/13 18:07:36 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ope_bubble_sort(t_game_lists *game)
{
	int	first;
	int	second;

	while (get_index_of(game->stack_a) != 1
		|| !is_ascending_order(game->stack_a))
	{
		first = get_int_value_of(game->stack_a);
		second = get_int_value_of((game->stack_a)->next_p);
		if (first > second && second != 1)
		{
			operate_sa(game);
		}
		operate_ra(game);
	}
}
