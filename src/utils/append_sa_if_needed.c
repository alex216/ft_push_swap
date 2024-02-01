/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_sa_if_needed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:33:06 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 13:04:01 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	append_sa_if_needed(t_game_lists *game_lists)
{
	int	first;
	int	second;
	int	third;

	if (is_ascending_order(game_lists->stack_a))
		return ;
	first = get_int_value_of(game_lists->stack_a);
	second = get_int_value_of((game_lists->stack_a)->next_p);
	third = get_int_value_of((game_lists->stack_a)->next_p->next_p);
	if (_is_two_one_three(first, second, third) || _is_descending_order(first,
			second, third) || _is_one_three_two(first, second, third))
		operate_sa(game_lists);
}
