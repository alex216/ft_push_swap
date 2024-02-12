/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_procedure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:41:47 by yliu              #+#    #+#             */
/*   Updated: 2024/02/09 18:07:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_procedure(t_game_lists *game_lists)
{
	int	a_size;

	if (is_ascending_order(game_lists->stack_a))
		return ;
	a_size = ft_dl_lstsize(game_lists->stack_a);
	if (a_size == 2)
		operate_sa(game_lists);
	else if (a_size >= 3 && a_size <= 5)
		ope_three_four_five_node(game_lists);
	else if (a_size < 150)
		ope_select_insert(game_lists);
	else
		ope_quick_sort(game_lists);
	return ;
}
